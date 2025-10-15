# programa que le a largura e altura de uma parede em metros, calcula a sua área e a quantidade de tinta necessária para pintá-la, sabendo que cada litro de tinta, pinta uma área de 2m².

larg = float(input('Largura da parede (m): '))
alt = float(input('Altura da parede (m): '))
area = larg * alt
print('Sua parede tem a dimensão de {}x{} e sua área é de {:.2f}m².'.format(larg, alt, area))
tinta = area / 2
print('Para pintar essa parede, você precisará de {:.2f} litros de tinta.'.format(tinta))
