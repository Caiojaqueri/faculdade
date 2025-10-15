#escreva um programa que pergunte a quantidade de km percorridos por um carro alugado e a quantidade de dias pelos quais ele foi alugado. Calcule o preço a pagar, sabendo que o carro custa R$60 por dia e R$0,15 por km rodado.

dias = int(input('Digite a quantidade de dias que o carro foi alugado: '))
km = float(input('Digite a quantidade de km percorridos: '))
pago = (dias * 60) + (km * 0.15)
print('O total a pagar pelo aluguel do carro é de R${:.2f}'.format(pago))
