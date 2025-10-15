# leia um número e mostre se ele é par ou ímpar 
numero = int(input('Me dia um número qualquer: '))
if numero % 2 == 0:
    print('O número {} é PAR'.format(numero))
else:
    print('O número {} é ÍMPAR'.format(numero))
