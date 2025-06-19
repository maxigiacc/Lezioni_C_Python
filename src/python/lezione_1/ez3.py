'''
# Input: temperatura in Fahrenheit
fahrenheit = float(input("Inserisci la temperatura in gradi Fahrenheit: "))

# Conversione
celsius = (5 / 9) * (fahrenheit - 32)

# Output
print(f"{fahrenheit} gradi Fahrenheit corrispondono a {celsius:.2f} gradi Celsius")

if celsius >= 28:
    print("Fa caldo")
elif celsius < 28 and celsius >= 16:
    print("Si sta bene")
elif celsius < 16 and celsius > 0:
    print("Freddino")
else:
    print("Si gela")

iterazioni = int(input("Quante iterazioni vuoi eseguire? "))

for i in range(iterazioni):
    print(f"Numero {i}")

frutti = ["mela", "pera", "banana"]     #liste
verdure = ("lattuga", "melanzana", "zucchina") #tuple
dolci = {"tiramisù", "panna cotta", "cannolo"} #set

for frutto in frutti:
    print(f"{frutto}")

for verdura in verdure:
    print(f"{verdura}")

for dolce in dolci:
    print(f"{dolce}")
'''

x = 0
while x < 5:
    if x == 1:
        x+=1
        continue
    if x == 4:
        break   #uscita dal while
    print(f"x vale {x}")
    x += 1


