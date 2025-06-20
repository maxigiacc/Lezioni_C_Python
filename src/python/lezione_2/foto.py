import os
import datetime

def rinomina_foto():
    cartella = "/Users/massimogiaccone/Desktop/Foto/Foto_samsung"
    data_oggi = datetime.date.today().strftime("%Y%m%d")
    
    for i, filename in enumerate(os.listdir(cartella)):
        if filename.lower().endswith(('.jpg', '.jpeg', '.png')):
            estensione = filename.split('.')[-1]
            nuovo_nome = f"SAM_{data_oggi}_{i:03d}.{estensione}"
            
            percorso_vecchio = os.path.join(cartella, filename)
            percorso_nuovo = os.path.join(cartella, nuovo_nome)
            
            os.rename(percorso_vecchio, percorso_nuovo)
            print(f"Rinominato: {filename} -> {nuovo_nome}")

rinomina_foto()