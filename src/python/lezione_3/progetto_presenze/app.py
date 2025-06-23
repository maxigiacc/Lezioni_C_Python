from flask import Flask, jsonify, request, render_template, redirect, url_for, send_file
import csv
import os
from io import StringIO, BytesIO

app = Flask(__name__)
CSV_FILE = "presenze.csv"

def load_presenze():
    if not os.path.exists(CSV_FILE):
        return []
    with open(CSV_FILE, newline="") as f:
        reader = csv.DictReader(f)
        return list(reader)

def save_presenze(presenze):
    with open(CSV_FILE, "w", newline="") as f:
        fieldnames = ["nome", "cognome", "data"]
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(presenze)

@app.route("/")
def index():
    data_filter = request.args.get("data")
    presenze = load_presenze()
    if data_filter:
        presenze = [p for p in presenze if p["data"] == data_filter]
    return render_template("index.html", presenze=presenze, data_filter=data_filter or "")

@app.route("/add", methods=["POST"])
def add_presenza():
    nome = request.form["nome"]
    cognome = request.form["cognome"]
    data = request.form["data"]
    presenze = load_presenze()
    presenze.append({"nome": nome, "cognome": cognome, "data": data})
    save_presenze(presenze)
    return redirect(url_for("index"))

@app.route("/delete/<int:index>")
def delete_presenza(index):
    presenze = load_presenze()
    if 0 <= index < len(presenze):
        presenze.pop(index)
        save_presenze(presenze)
    return redirect(url_for("index"))

# 📥 Download CSV filtrato o completo
@app.route("/download")
def download_csv():
    data_filter = request.args.get("data")
    presenze = load_presenze()
    if data_filter:
        presenze = [p for p in presenze if p["data"] == data_filter]

    # Scrivi su stringa CSV
    si = StringIO()
    fieldnames = ["nome", "cognome", "data"]
    writer = csv.DictWriter(si, fieldnames=fieldnames)
    writer.writeheader()
    writer.writerows(presenze)
    csv_text = si.getvalue()

    # Converti in BytesIO
    bio = BytesIO(csv_text.encode("utf-8"))
    bio.seek(0)

    return send_file(
        bio,
        mimetype="text/csv",
        as_attachment=True,
        download_name=f"presenze{'_' + data_filter if data_filter else ''}.csv"
    )

if __name__ == "__main__":
    app.run(debug=True)
