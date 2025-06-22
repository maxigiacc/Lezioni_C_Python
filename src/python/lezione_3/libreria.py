from flask import Flask, jsonify, request
import json
import os

app = Flask(__name__)
BOOKS_FILE = "books.json"

# 🔁 Carica i dati dal file se esiste
def load_books():
    if os.path.exists(BOOKS_FILE):
        with open(BOOKS_FILE, "r") as f:
            return json.load(f)
    return []

# 💾 Salva i dati nel file
def save_books():
    with open(BOOKS_FILE, "w") as f:
        json.dump(books, f, indent=4)

# Inizializzazione
books = load_books()

@app.route("/books", methods=["GET"])
def get_books():
    return jsonify(books)

@app.route("/books", methods=["POST"])
def add_book():
    data = request.get_json()
    books.append(data)
    save_books()
    return jsonify(data), 201

@app.route("/books/<int:index>", methods=["DELETE"])
def delete_book(index):
    if 0 <= index < len(books):
        removed = books.pop(index)
        save_books()
        return jsonify(removed)
    return jsonify({"error": "Not found"}), 404

@app.route("/books/<int:index>", methods=["PUT"])
def update_book(index):
    if 0 <= index < len(books):
        data = request.get_json()
        books[index] = data
        save_books()
        return jsonify(data)
    return jsonify({"error": "Not found"}), 404


if __name__ == "__main__":
    app.run(debug=True)

'''
ADD
curl -X POST http://127.0.0.1:5000/books \
     -H "Content-Type: application/json" \
     -d '{"title": "1984", "author": "George Orwell"}'

curl -X PUT http://127.0.0.1:5000/books/0 \
     -H "Content-Type: application/json" \
     -d '{"title": "Animal Farm", "author": "George Orwell"}'
'''