# Estrutura condicional aninhadas 02

#outra forma de fazer é simplificando, ao invés de usar vários blocos de elif, utilize or 

num = int(input('Digite um número até 5: '))
if num > 5:
    print('Você digitou o número errado, {} é passou do 5.'.format(num))
elif num == 1 or num == 2 or num == 3 or num == 4:
    print('Você digitou o número certo! {} é está dentro de 5.'.format(num))

