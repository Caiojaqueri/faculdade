#média alunos com condiões de aprovação, recuperação e reprovação

n1 = float(input('Primeira nota: '))
n2 = float(input('Segunda nota: '))
m = (n1 + n2) / 2
if m >= 7.0 :
    print('Sua média foi {:.1f} e você está APROVADO!'.format(m))
