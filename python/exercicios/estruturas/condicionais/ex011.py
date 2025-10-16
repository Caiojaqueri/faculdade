#média alunos com condiões de aprovação, recuperação e reprovação

n1 = float(input('Primeira nota: '))
n2 = float(input('Segunda nota: '))
m = (n1 + n2) / 2
if m >= 6.0 :
    print('Sua média foi boa e você está APROVADO!')
else:
    print('A sua média foi ruim e você está de RECUPERAÇÃO!')

#OU print('PARABENS' if m >= 6.0 else 'ESTUDE MAIS!') - estrutura condicional simplificada' mas dessa forma é um pouco mais complicado de entender, é capaz de confundir quem está aprendendo
