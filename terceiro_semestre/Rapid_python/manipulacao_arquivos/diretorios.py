# criar um diretório
import os
from pathlib import Path

os.mkdir('teste')

Path("caminho_teste").mkdir(parents=True, exist_ok=True)


# listar conteúdo 
conteudo = os.listdir('.')
print(conteudo)

caminho = Path('.') 
for arquivo in caminho.glob('*.txt'):
    print(arquivo.name)
# filtrando p apenas arquivos .txt


# renomera de antigo para novo
os.rename("projeto_antigo", "projeto_novo")


#usando o pathlib
Path("projeto_antigo").rename("projeto_novo")