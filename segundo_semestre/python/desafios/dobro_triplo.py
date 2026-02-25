# programa que leia um número inteiro e mostre na tela o seu dobro, triplo e raiz quadrada

n1 = int(input('Digite um valor:'))
dobro = n1 * 2
triplo = n1 * 3
raiz = n1 ** (1/2)
print('O dobro de {} é {}, o triplo é {} e a raiz quadrada é {:.2f}'.format(n1, dobro, triplo, raiz))
