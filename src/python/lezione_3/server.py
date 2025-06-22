from http.server import BaseHTTPRequestHandler, HTTPServer
import json
from urllib.parse import urlparse, parse_qs

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
            
        else:
            self.send_response(404)
            self.end_headers()
            self.wfile.write(b"404 - Pagina non trovata")

# Avvio del server
server = HTTPServer(('localhost', 8000), MyHandler)
print("Server avviato su http://localhost:8000")
server.serve_forever()