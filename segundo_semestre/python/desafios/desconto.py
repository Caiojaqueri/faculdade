#programa que le o preço de um produto e mostre seu novo preço com 5% de desconto 

preco = float(input('Digite o preço do seu produto: R$'))
desconto = preco*5/100
novo_preco = preco - desconto
#ou novo = preco - (preco*5/100)
print('O produto que custava R${:.2f}, na promoção vai custar R${:.2f} com 5% de desconto.'.format(preco, novo_preco))
