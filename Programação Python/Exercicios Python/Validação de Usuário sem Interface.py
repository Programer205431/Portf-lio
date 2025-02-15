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

