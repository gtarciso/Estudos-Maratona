while 1:
	try:
		text = input().split(' ')
		alit = 0
		flag = 0
		ant_char = ''
		for obj in text:
			actual = obj[0].lower()
			if actual == ant_char and flag == 0:
				alit += 1
				flag = 1
			if actual != ant_char:
				flag = 0

			ant_char = actual


		print(alit)

	except EOFError:
		break