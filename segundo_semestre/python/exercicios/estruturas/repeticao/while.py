'''for c in rage (0,11)
        print(c)
    print('FIM')'''

#c = 1
#while c < 11: - enquanto c for igual a 10
    #print(c)  -printe c 
    #c+=1  - c = c + 1 de um e um 
#print('FIM')

n = 1
par = impar = 0 
while n != 0:
    n = int(input('Digite um valor: '))
    if n % 2 == 0:
        par += 1
    else:
        impar += 1
print('Você digitou {} números pares e {} números ímpares'.format(par, impar))
