def fattoriale(n):
    ris= 1
    for i in range (1, 1+n):
        ris= ris*i
    return ris
print(fattoriale(4))