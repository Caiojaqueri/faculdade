# métodos de manupulação de string

# strip 
# remove os espaços em branco do início e do fim da string
texto = "   Olá Mundo   "
print(texto.strip())
# saída: "Olá Mundo"


#split
# divide a string em uma lista de palavras
frase = "Puthon, é, muito, legal"
lista = frase.split(",")
#saída: ['Puthon', ' é', ' muito', ' legal']


#count
# conta quantas vezes um caractere ou subtexto aparece dentro da string
frase = "O rato roeu a roupa do rei"
qtd_r = frase.count('r')
print(f"A letra 'r' aparece {qtd_r}vezes.")
#saída: A letra 'r' aparece 5 vezes.


#join
#junta uma lista em uma única string, usando um separador
lista = ['python', 'é', 'muito', 'legal']
frase = ".".join(lista)
print(frase)
#saída: "python.é.muito.legal"