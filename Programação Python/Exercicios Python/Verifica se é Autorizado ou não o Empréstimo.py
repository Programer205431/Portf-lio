renda=int(input("Digite o valor de sua renda mensal: "))
valor=int(input("Digite o valor do empréstimo: "))
e=(valor<=renda*10)
prestaçao=int(input("Informe em quantas prestações deseja: "))
total=valor/prestaçao 
if(total<=renda*0.3):
    print(f"O empréstimo foi permitido, o valor da parcela será de {total}")
else:
    print("Empréstimo não permitido")
