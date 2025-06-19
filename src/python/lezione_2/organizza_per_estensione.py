import os
import shutil

def organizza_per_estensione(directory):
    for item in os.listdir(directory):
        if os.path.isfile(os.path.join(directory, item)):
            estensione = item.split('.')[-1]
            estensione_dir = os.path.join(directory, estensione)
            if not os.path.exists(estensione_dir):
                os.makedirs(estensione_dir)
            shutil.move(os.path.join(directory, item), os.path.join(estensione_dir, item))

organizza_per_estensione('/Users/massimogiaccone/Desktop/ERASMUS')