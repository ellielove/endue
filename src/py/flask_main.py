from flask import Flask

app = Flask(__name__)


@app.route('/', methods=["GET"])
def hello():
    return 'Ellie is making this thing work!'


if __name__ == '__main__':
    app.run(host='127.0.0.1', port='5000')
