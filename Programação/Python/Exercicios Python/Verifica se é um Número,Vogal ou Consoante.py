x=str(input("digite um caractere: "))
if x in "AEIOUaeiou":
    print(f"esta letra é vogal")
elif x.isnumeric():
    print(f"isto é um número ")
else:
    print(f"a letra é consoante ")
    
