numbers = []

n = int(input())

for i in range(n):
	numbers.append(int(input()))


numbers.sort()

atual = numbers[0]
i = 1
cont = 1
tuples_list = []
while i < len(numbers):
	if numbers[i] != atual:
		tuples_list.append((atual, cont))
		cont = 1
		atual = numbers[i]
	else:
		cont += 1

	i += 1

tuples_list.append((atual, cont))

for i in range(len(tuples_list)):
	num = tuples_list[i][0]
	occ = tuples_list[i][1]
	print(str(num) + ' aparece ' + str(occ) + ' vez(es)')