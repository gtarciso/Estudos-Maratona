while 1:
	text = input().split(' ')
	n = int(text[0])
	b = int(text[1])
	if n == 0 and b == 0:
		break

	n_vector = [0] * (n+1)
	numbers = []
	x = input().split(' ')
	for i in range(b):
		numbers.append(int(x[i]))

	numbers.sort(reverse = True)
	for i in range(b):
		for j in range(i, b):
			calc = numbers[i] - numbers[j]
			n_vector[calc] = 1
	
	flag = 0
	for i in range(len(n_vector)):
		if n_vector[i] == 0:
			flag = 1
			break


	if flag == 0:
		print('Y')
	else:
		print('N')