# programa que simula o jogo pedra, papel e tesoura 

from random import randint
from time import sleep

itens = ('PEDRA', 'PAPEL', 'TESOURA')
computador = randint(0, 2)# computador faz a escolha de 0 a 2
print('o computador escolheu {}'.format(itens[computador]))# assim mostra as escolhas do computador quando executado só que ao invez dele mostrar os númerso do randint ele mostra os itens pedra, papel e tesoura

print('''SUAS OPÇÕES SÃO:
[ 0 ] PEDRA
[ 1 ] PAPEL
[ 2 ] TESOURA''')
jogador = int(input('Qual é sua jogada? '))

print('JO')
sleep(1)
print('KEN')
sleep(1)
print('PO!!!')

print('-=-'*11)
print('Computador jogou {}'.format(itens[computador]))
print('Jogador jogou {}'.format(itens[jogador]))
print('-=-'*11)

if computador == 0: # se o computador jogou PEDRA
    if jogador == 0: 
        print('EMPATE!')
    elif jogador == 1:
        print('JOGADOR VENCE!')
    elif jogador == 2:
        print('COMPUTADOR VENCE!')
    else:
        print('JOGADA INVÁLIDA! TENTE NOVAMENTE.')

elif computador == 1: # computador jogou PAPEL
    if jogador == 0:
        print('COMPUTADOR VENCE!')
    elif jogador == 1:
        print('EMPATE!')
    elif jogador == 2:
        print('JOGADOR VENCE!')
    else:
        print('JOGADA INVÁLIDA! TENTE NOVAMENTE.')

elif computador == 2: # computador jogou TESOURA
    if jogador == 0:
        print('JOGADOR VENCE!')
    elif jogador == 1:
        print('COMPUTADOR VENCE!')
    elif jogador == 2:
        print('EMPATE!')
    else:
        print('JOGADA INVÁLIDA! TENTE NOVAMENTE.')

    

