from flask import Flask,jsonify

app = Flask(__name__)

@app.route('/')
def hello_world():
    return "Hello World"

@app.route("/prime/<int:num>")
def prime(num):

    flag = False

    if num > 1:
        for i in range(2, num):
            if (num % i) == 0:
                flag = True
                break

    if flag:
        result = {
            "num":num,
            "isPrime":False
        }
    else:
        result = {
            "num":num,
            "isPrime":True
        }

    return jsonify(result)


if __name__ == "__main__":
    app.run(debug = True)