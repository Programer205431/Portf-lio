usuario=("joão@gmail.com")

leitura=""
while(leitura !=usuario):
	leitura=input("digite Nome de usuário: ")
	if leitura==usuario:
		print('Usuário encontrado, agora digite a senha')
	else:
		print('nome de usuário incorreto')
senha="204075"
leitura2=""
while(leitura2 != senha):
    leitura2=input("senha: ")
    if leitura2==senha:            
            print('Acesso Liberado')
    else:
	    print('Senha incorreta, tente novamente...')
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
            print("vc é o cara")
