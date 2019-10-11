while 1:
	numbers = input().split(' ')
	x = int(numbers[0])
	y = int(numbers[1])
	if x == 0 and y == 0:
		break

	value = x+y

	text = str(value)
	new_number = ''
	for i in range(len(text)):
		if text[i] != '0':
			new_number += text[i]

	print(new_number)