while True:
    valor=int(input("Digite sua Idade: "))
    if valor < 11:
            print("Criança")
            print("Não Possui idade para tirar habilitação")
    elif valor < 18:
            print("Adolescente")
            print("Não Possui idade para tirar habilitação")
    elif valor <60:
            print("Adulto")
            print("Possui idade para tirar habilitação")
    elif valor > 60:
            print("Idoso")
            print("Recomendável não dirigir mais em caso de problemas visuais")
    else:
            print(".")