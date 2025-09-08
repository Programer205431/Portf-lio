while True:
    x=float(input("Digite um número: "))
    if x<0:
        print("O número é Negativo")
    elif x==0:
        print("Número Neutro")
    else:
        print("O número é Positivo")
    resp=str(input("Deseja Continuar?: ")).strip().upper()
    if resp=="N":
        break
       
