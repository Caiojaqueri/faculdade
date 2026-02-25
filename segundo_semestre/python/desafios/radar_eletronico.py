# simule um radar eletrônico, se o usuário ultrapassar a velocidade máxima 80km/h, mostre uma mensagem que ele foi multado. A multa vai custar R$7,00 por cada km acima do limite

velocidade = float(input('Qual velocidade atual do carro? '))
if velocidade > 80:
    print('MULTADO! Você excedeu o limite de velocidade que é 80km/h')
    multa = (velocidade - 80) * 7
    print('Você deve pagar uma multa de R${:.2f}'.format(multa))
print('Tenha uma boa viagem! Diriga com segurança! ') #condição simples sem utilizar o else


