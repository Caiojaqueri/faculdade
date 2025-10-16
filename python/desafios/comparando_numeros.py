# programa que leia dois números e mostre qual é o maior e qual é o menor

num1 = int(input('Primeiro número: '))
num2 = int(input('Segundo número: '))
if num1 > num2:
    print('O maior número é o PRIMEIRO')
elif num1 < num2:
    print('O maior número é o SEGUNDO')
else:
    print('Os dois números são IGUAIS')
    