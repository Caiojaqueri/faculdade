# pergunte o valor da casa, o salário do usuário e em quantos anos ele vai pagar. Calcule o valor da prestação mensal, sabendo que não pode exceder de 30% do salário ou então o empréstimo será negado.

casa = float(input('Qual o valor da casa? R$ '))
salario = float(input('Qual o salário do comprador? R$ '))
anos = int(input('Quantos anos de financiamento? '))
prestacao = casa / (anos * 12)# preço da casa dividivo por quantos meses vai pagar
minimo = salario * 30 / 100 # 30% do salário
if prestacao <= minimo: #se a prestação for menor ou igual ao mínimo
    print('Empréstimo pode ser CONCEDIDO!')
else:
    print('Empréstimo NEGADO!')
print('Para pagar uma casa de R$ {:.2f} em {} anos'.format(casa, anos), end=' ')
print('a prestação será de R$ {:.2f}'.format(prestacao))
