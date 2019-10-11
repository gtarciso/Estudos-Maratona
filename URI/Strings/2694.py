def is_number(a):
	number = ord(a)
	if number >= 48 and number <= 57:
		return 1
	else:
		return 0


n = int(input())

for i in range(n):
	st = input()
	num = []
	num.append('')
	num.append('')
	num.append('')
	sentry = 0
	index = 0
	j = 0
	while j < len(st):
		aux = is_number(st[j])
		if aux == 1:
			num[index] += st[j]
			sentry = 1

		if aux == 0 and sentry == 1:
			index += 1
			sentry = 0
			

		j += 1

	sum_numb = 0
	for k in range(3):
		sum_numb += int(num[k])

	print(sum_numb)
