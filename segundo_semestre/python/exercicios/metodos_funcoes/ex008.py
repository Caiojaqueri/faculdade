#MANIPULAÇÃO DE STRINGS


frase = 'Curso em Vídeo Python'
#FATIAMENTO
print(frase[9]) #imprime a letra na posição 9
print(frase[9:13]) #imprime da posição 9 até a 13
print(frase[9:21:2]) #imprime da posição 9 até a 21 pulando de 2 em 2
print(frase[:5]) #imprime do início até a posição 5
print(frase[15:]) #imprime da posição 15 até o final
print(frase[9::3]) #imprime da posição 9 até o final pulando de 3 em 3
#ANÁLISE
print(len(frase)) #imprime o tamanho da frase
print(frase.count('o')) #imprime quantas vezes a letra 'o' aparece
print(frase.count('o',0,13)) #imprime quantas vezes a letra 'o' aparece entre as posições 0 e 13
print(frase.find('deo')) #imprime a posição onde começa a palavra 'deo'
print(frase.find('Android')) #imprime -1 pois a palavra não existe na frase
print('Curso' in frase) #imprime True se a palavra 'Curso' existe na frase
#TRANSFORMAÇÃO
print(frase.replace('Python', 'Android')) #substitui a palavra 'Python' por 'Android'
print(frase.upper()) #transforma todas as letras em maiúsculas
print(frase.lower()) #transforma todas as letras em minúsculas
print(frase.capitalize()) #transforma a primeira letra em maiúscula
print(frase.title()) #transforma a primeira letra de cada palavra em maiúscula
print(frase.strip()) #remove os espaços inúteis no início e no final da frase
print(frase.rstrip()) #remove os espaços inúteis no final da frase
print(frase.lstrip()) #remove os espaços inúteis no início da frase
#DIVISÃO
print(frase.split()) #divide a frase em palavras e cria uma lista
#JUNÇÃO
print('-'.join(frase)) #junta a frase com o caractere '-' entre cada letra
