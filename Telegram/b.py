import requests

base_url = "https://api.telegram.org/bot5236676435:AAGdDrjr6N4cm8sP6lMeOwnZWuC4M8iB5r8/getUpdates"


parameters = {
    "offset" : "994059489",
    "limit":2
}

resp = requests.get(base_url, data = parameters)
print(resp.text)
