# Estrutura de condições 
tempo = int(input('Quanto tempo tem seu carro?: '))
if tempo <= 3:
    print('Carro novo!')
else: 
    print('Carro velho!')
print('--FIM--')
# os comandos com a identação para dentso, é o que define o bloco de código que pertence ao if ou ao else. Um ou outro vai aparecer, nunca os dois juntos.

# Condição Simplificada 
tempo = int(input('Quanto tempo tem seu carro?: '))
print('Carro novo!' if tempo <= 3 else 'Carro velho!')
print('--FIM--')