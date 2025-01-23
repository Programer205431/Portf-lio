
x=int(input("Digite um valor: "))
y=int(input("Digite um valor: "))

if (x == 0.0 and y == 0.0) :
  print(f"Origem\n");
 
elif (x > 0 and y > 0):
  print(f"Q1\n");
 
elif (x < 0 and y > 0):
  print(f"Q2\n");
 
elif (x < 0 and y < 0):
  print(f"Q3\n");
 
elif (x > 0 and y < 0):
  print("Q4\n");
 
elif (x == 0):
  print(f"Eixo Y\n");
 
elif (y == 0) :
  print(f"Eixo X\n"); 
 
