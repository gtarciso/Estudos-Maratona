while 1:
	n = input()
	result = n.split(' ')
	c = result[0]
	st = result[1]

	if c == '0' and st == '0':
		break

	final = ''
	for i in range(len(st)):
		if st[i] != c:
			final += st[i]

	flag_zero = 0
	for i in range(len(final)):
		if final[i] == '0':
			flag_zero += 1

	if flag_zero == len(final):
		print(0)

	elif final == '':
		print(0)

	else:
		print(int(final))
