x=int(input("Digite um Valor: "))
y=int(input("Digite um Valor: "))
z=int(input("Digite um Valor: "))
if x>z and y>z:
    print(x+y)
elif z>x and x>y:
    print(z+x)
else:
    print(y+z)
