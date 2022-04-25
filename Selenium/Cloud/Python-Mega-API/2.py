import collection
import re
import requests
import json
from mega.crypto import base64_to_a32, base64_url_decode, decrypt_attr, decrypt_key

def get_nodes_in_shared_folder(root_folder: str) -> dict:
    data = [{"a": "f", "c": 1, "ca": 1, "r": 1}]
    response = requests.post(
        "https://g.api.mega.co.nz/cs",
        params={'id': 0,  # self.sequence_num
                'n': root_folder},
        data=json.dumps(data)
    )
    json_resp = response.json()
    return json_resp[0]["f"]

def parse_folder_url(url: str) -> tuple([str, str]):
    "Returns (public_handle, key) if valid. If not returns None."
    REGEXP1 = re.compile(r"mega.[^/]+/folder/([0-z-_]+)#([0-z-_]+)(?:/folder/([0-z-_]+))*")
    REGEXP2 = re.compile(r"mega.[^/]+/#F!([0-z-_]+)[!#]([0-z-_]+)(?:/folder/([0-z-_]+))*")
    m = re.search(REGEXP1, url)
    if not m:
        m = re.search(REGEXP2, url)
    if not m:
        print("Not a valid URL")
        return None
    root_folder = m.group(1)
    key = m.group(2)
    # You may want to use m.group(-1)
    # to get the id of the subfolder
    return (root_folder, key)

def decrypt_node_key(key_str: str, shared_key: str) -> tuple([int, ...]):
    encrypted_key = base64_to_a32(key_str.split(":")[1])
    return decrypt_key(encrypted_key, shared_key)


(root_folder, shared_enc_key) = parse_folder_url("https://mega.nz/folder/hdtiTQbR#B2aNe25VYWnkqgWD2xi5og")
shared_key = base64_to_a32(shared_enc_key)
nodes = get_nodes_in_shared_folder(root_folder)
for node in nodes:
    key = decrypt_node_key(node["k"], shared_key)
    if node["t"] == 0: # Is a file
        k = (key[0] ^ key[4], key[1] ^ key[5], key[2] ^ key[6], key[3] ^ key[7])
    elif node["t"] == 1: # Is a folder
        k = key
    attrs = decrypt_attr(base64_url_decode(node["a"]), k)
    file_name = attrs["n"]
    file_id = node["h"]
    print(key)