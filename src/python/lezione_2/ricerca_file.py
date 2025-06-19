import os

def trova_file(directory, estensione):
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(estensione):
                print(os.path.join(root, file))

trova_file('/Users/massimogiaccone/Desktop/ERASMUS', '.pdf')