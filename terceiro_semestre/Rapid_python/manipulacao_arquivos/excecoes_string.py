def ler_relatorio(nome_arquivo):
    # Verifica se o nome do arquivo termina com '.txt', caso contrário, adiciona a extensão
    if not nome_arquivo.lower().endswith('.txt'):
        nome_arquivo += '.txt'  
        print(f"--- Ajustando nome para: {nome_arquivo} ---")

    try:
        # tenta abrir o arquivo para leitura
        with open(nome_arquivo, 'r', encoding='utf-8',) as arquivo:
            conteudo = arquivo.read()
            print("Conteúdo do Relatório: ")
            print(conteudo)

    except FileNotFoundError:
        print(f"Erro: O arquivo '{nome_arquivo}' não foi encontrado no diretório atual.")

    except PermissionError:
        print(f"Erro: Permissão negada para acessar o arquivo '{nome_arquivo}'.")

arquivo_usuario = input("Digite o nome do relatório que deseja ler: ")

ler_relatorio(arquivo_usuario)
