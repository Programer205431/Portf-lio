continuar=str("deseja calcular novamente?")
repete=True
while repete:                                   #abre a estrutura de repetição
    def calculo(media):
            x=int(input("digite a nota 1:"))
            y=int(input("digite a nota 2:"))
            i=int(input("digite a nota 3:"))
            z=int(input("digite a nota 4:"))
            media=((x+y+i+z)/4)                 #efetua o cálculo da média
            if x >10:
                print("valor não existente, escolha um valor de 0 a 10")
                print(calculo("media"))
            if y >10:
                print("valor não existente, escolha um valor de 0 a 10")
                print(calculo("media"))
            if i >10:
                print("valor não existente, escolha um valor de 0 a 10")
                print(calculo("media"))
            if z >10:
                print("valor não existente, escolha um valor de 0 a 10")
                print(calculo("media"))
            else:
                print(media)
                continuar=str(input("deseja calcular novamente?"))
                
    calculo("media")                            #chama a função
    
    if continuar== "Sim" and "S":               #após executar a função se o usuário responder a pergunta com Sim ou S a repetição será feita, do contrário o código será encerrado
        print(calculo())
    else:
            repete=False
            break