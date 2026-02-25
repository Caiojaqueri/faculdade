#programa que le o valor do seu salário e faça o reajuste de aumento de 15% 

salario = float(input('Digite o seu salário atual: R$'))
novo_sal = salario + (salario*15/100)
print('Seu salário de R${:.2f} com 15% de aumento vai para R${:.2f}'.format(salario, novo_sal))
