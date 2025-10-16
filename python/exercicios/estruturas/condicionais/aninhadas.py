# Estrutura condicional aninhada 

nome = str(input("Digite seu nome: "))
if nome == 'Caio':
    print('Que lindo seu nome!')

#se nome for pedro ou maria ou joão
elif nome == 'Pedro' or nome == 'Maria' or nome == 'João':
    print('Seu nome é bem popular no Brasil.')

#se nome estiver dentro da string
elif nome in 'Ana Claudia Jessica Juliana':
    print('Belo nome feminino.')

else:
    print('Seu nome é bem normal.')
print('Tenha um bom dia, {}!'.format(nome))

#elif = else if da pra utilizar vários elifs