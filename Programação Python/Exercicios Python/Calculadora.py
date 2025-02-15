continuar=str("deseja calcular novamente?")
repete=True
while repete:  
    def calculo(calcular):
        x=int(input("Digite um número: "))
        y=int(input("Digite um número: "))
        z=str(input("digite o método de calculo: "))
        if z=="+":
                    print(x+y);
        elif z=="-":
                    print(x-y);
        elif z=="x" and "X":
                    print(x*y);
        else:
                    print(x/y)
        continuar=str(input("deseja calcular novamente?"))
                                
            
    calculo("calcular")                            #chama a função
    if continuar == "Sim" and "S" and "s" and "sim":               #após executar a função se o usuário responder a pergunta com Sim ou S a repetição será feita, do contrário o código será encerrado
        calculo()
    else:
        repete=False
        
