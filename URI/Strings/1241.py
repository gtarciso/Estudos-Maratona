n = int(input())

i = 0

while i < n:
	entrada = input()
	st = entrada.split(' ')

	num1 = st[0]
	num2 = st[1]

	if len(num2) > len(num1):
		print("nao encaixa")
		i += 1
		continue

	parada = len(num2)-1
	totaln1 = len(num1)-1
	totaln2 = len(num2)-1
	flag = 0
	while parada != 0:
		if num1[totaln1-parada] != num2[totaln2-parada]:
			flag = 1

		parada -= 1


	if flag == 0:
		print("encaixa")
	else:
		print("nao encaixa")
	i += 1