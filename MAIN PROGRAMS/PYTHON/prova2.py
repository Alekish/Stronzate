def myMax(a,b):
    if(a>b): return a
    else: return b

a = int(input("inserisci un numero: "))
b = int(input("inserisci un altro numero: "))

print("il massimo e' " + str(myMax(a,b)))