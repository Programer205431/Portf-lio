x=(input("qual combustivel voce deseja:[A/G] ")).strip().lower()
if x[0]=="a":
    y=int(input("digite a quantidade de litros que deseja: "))
    if y<=25:
        z=1.90*0.98*y
        print(f"o valor total a se pagar é: {z}")
    else:
        z=1.90*0.96*y
        print(f"o valor total a se pagar é: {z}")
elif x[0]=="g":
    y=int(input("digite a quantidade de litros que deseja: "))
    if y<=25:
        z=2.70*0.97*y
        print(f"o valor total a se pagar é: {z}")
    else:
        z=2.70*0.95*y
        print(f"o valor total a se pagar é: {z}")
else:
    print("voce nao digitou a letra certa seu animal")
    

