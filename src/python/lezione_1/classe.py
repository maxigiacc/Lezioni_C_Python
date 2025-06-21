class Cane:
    def __init__(self, nome, razza):
        self.nome = nome
        self.razza = razza

    def abbaia(self):
        print("Woof!")

    def __str__(self):
        return {self.nome}



golden = Cane("Cooper", "Golden Retriever")
golden.abbaia()
