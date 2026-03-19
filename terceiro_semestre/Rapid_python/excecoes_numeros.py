try:
    entrada = input("Digite sua idade:" )
    #idade é tipo inteiro, mas a entrada é string, então precisamos converter
    idade = int(entrada)

    if idade >= 18:
        print("Você é maior de idade.")
    else:
        print("Você é menor de idade.")

except ValueError:
    print(f"Erro: '{entrada}' não é um número inteiro válido!")

print("Obrigado por usar nosso sistema!")
