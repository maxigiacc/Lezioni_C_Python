from flask import Flask, jsonify, json
app = Flask(__name__)

@app.route('/')
def home():
    return "<h1>Benvenuto nel nostro server Python!</h1>"

@app.route('/api/status')
def status():
    return jsonify({"status": "online", "server": "Flask Server"})

@app.route('/profile')
def profile():
    with open("./dati.json", "r", encoding="utf-8") as f:
        profilo = json.load(f)
    return jsonify(profilo)
            

app.run(debug=True)