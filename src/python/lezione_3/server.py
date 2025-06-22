from http.server import BaseHTTPRequestHandler, HTTPServer
import json
from urllib.parse import urlparse, parse_qs

'''
Cosa abbiamo costruito:

BaseHTTPRequestHandler: classe base per gestire HTTP requests
Routing manuale: if/elif per diversi percorsi
Content-Type: specifichiamo HTML o JSON
Status codes: 200 (OK), 404 (Not Found)
HTTPServer: il vero server che ascolta sulla porta 8000

Concetti chiave:

Request/Response cycle
HTTP headers
URL parsing
Content negotiation

Questo è esattamente quello che fanno Flask, Django e FastAPI, ma con molto più zucchero sintattico!
'''


class MyHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        # Parsing dell'URL
        parsed_path = urlparse(self.path)
        
        if parsed_path.path == '/':
            self.send_response(200)
            self.send_header('Content-type', 'text/html')
            self.end_headers()
            self.wfile.write(b"<h1>Benvenuto nel nostro server Python!</h1>")
            
        elif parsed_path.path == '/api/status':
            self.send_response(200)
            self.send_header('Content-type', 'application/json')
            self.end_headers()
            response = {"status": "online", "server": "Python Custom Server"}
            self.wfile.write(json.dumps(response).encode())

        elif parsed_path.path == '/profilo':
            self.send_response(200)
            self.send_header('Content-type', 'application/json')
            self.end_headers()
            with open("./dati.json", "r", encoding="utf-8") as f:
                profilo = json.load(f)
            self.wfile.write(json.dumps(profilo).encode())
            
        elif parsed_path.path == '/x':
            self.send_response(200)
            self.send_header('Content-type', 'text/html')
            self.end_headers()
            x = 3
            html = f"<h1>Il valore della variabile x vale {x}!</h1>"
            self.wfile.write(html.encode())

        else:
            self.send_response(404)
            self.end_headers()
            self.wfile.write(b"404 - Pagina non trovata")

# Avvio del server
server = HTTPServer(('localhost', 8000), MyHandler)
print("Server avviato su http://localhost:8000")
server.serve_forever()