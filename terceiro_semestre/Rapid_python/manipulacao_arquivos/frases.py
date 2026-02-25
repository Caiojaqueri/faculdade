def main():
    print("Digite suas frases. Para finalizar, digite 'sair'.")
    frases = [] #lista que vai salvar as frases digitadas

    while True:
        frase = input("> ")
        if frase.lower() == 'sair':
            break
        frases.append(frase)
    # enquanto verdadeiro
          # frase vai receber o input do usuário
            # se a frase for igual a 'sair' (ignorando maiúsculas e minúsculas)
                # quebrar o loop
            # senão adicionar a frase à lista de frases

    with open("frases.txt", "w") as arquivo:
        for frase in frases:
            arquivo.write(frase + "\n")
    # com o arquivo aberto no modo write (escrita)
        # para cada frase na lista de frases
            # escrever a frase no arquivo seguida de uma nova linha

    print("Arquivo original criado. Agora vamos manipular os dados...")
    dados_modificados = [] # lista para salvar frases modificadas 

    with open("frases.txt", "r") as arquivo:
        for linha in arquivo:
            dados_modificados.append(linha.strip().upper())
    # com o arquivo aberto no modo read (leitura)
        # para cada linha no arquivo
            # adicionar a linha à lista de dados modificados, removendo espaços e convertendo para maiúsculas

    with open("frases.txt", "w") as arquivo:
        for linha in dados_modificados:
            arquivo.write(linha + "\n")
    # com o arquivo aberto no modo write (escrita)
        # para cada linha na lista de dados modificados
            # escrever a linha no arquivo seguida de uma nova linha

    print("O arquivo foi sobrescrito com os dados modificados. ")

if __name__ == "__main__":
    main()
# se o nome do módulo for igual a "__main__" (ou seja, se este arquivo for executado diretamente)
    # chamar a função main()