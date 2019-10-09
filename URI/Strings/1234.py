while 1:
	try:
		st = input()
		j = 0
		nova = ''
		for i in range(len(st)):
			if st[i] == ' ':
				nova += ' '
				continue

			if j%2 == 0:
				nova += st[i].upper()
				
			elif j%2 == 1:
				nova += st[i].lower()

			j += 1

		print(nova)
	except EOFError:
		break

