import sqlite3 as connector
# podendo também mudar as bibliotecas p/ mysql.connector, psycopg2 etc... 

# abertura de conexão
conexao = connector.connect("URL SQLite")

# aquisição de um cursor
cursor = conexao.cursor()

# execução comandos: SELECT.. CREATE..
cursor.execute("...")
cursor.fetchall() # para recuperar os dados da consulta SELECT

# efetivação do comando
conexao.commit()

# fechamento das conexões
cursor.close()
conexao.close()
