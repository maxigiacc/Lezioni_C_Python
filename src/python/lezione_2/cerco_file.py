import os 

def trova_file(cartella: str, estensione: str):
    for root, dirs, files in os.walk(cartella):
        for file in files:
            if file.endswith(estensione):
                print(os.path.join(root, file))

trova_file('/Users/massimogiaccone/Desktop', '.docx')