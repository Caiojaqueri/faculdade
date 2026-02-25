#conversor de moedas, de reais para dólares

din = float(input('Quanto dinheiro voê tem na carteira? R$: '))
dol = din / 5.47
print('Com R$ {:.2f} você pode comprar US$ {:.2f}'.format(din, dol))
