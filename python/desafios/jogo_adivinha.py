#jodo de adivinhar um numero junto com o computador
from random import randint #biblioteca para gerar numeros aleatorios
from time import sleep #biblioteca para fazer o programa "dormir" por alguns segundos
computador = randint(0, 5) #faz o computador "pensar" em um número de 0 a 5
print('-=-' * 20)
print('Vou pensar em um número entre 0 e 5. Tente adivinhar...')
print('-=-' * 20)
jogador = int(input('Em que número eu pensei? ')) #jogador tenta adivinhar
print('PROCESSANDO...')
sleep(3) #faz o programa "dormir" por 3 segundos
if jogador == computador:
    print('Parabens! Você conseguiu me vencer!')
else:
    print('Ganhei! Eu pensei no número {} e não no {}!'.format(computador, jogador))
