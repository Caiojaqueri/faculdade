#Estrutura condicional composta: quando tem o else
#estrutura condicional simples: quando não tem o else

nome = str(input('Qual é seu nome?: '))
if nome == 'Caio':
    print('Que nome lindo voê tem!')
else:
    print('Seu nome é tão normal!')
print('Bom dia, {}!'.format(nome))
