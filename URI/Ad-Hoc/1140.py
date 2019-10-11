while 1:
	st = input()
	if st == '*':
		break

	taut = st.split(' ')
	flag = 0
	letter = taut[0][0].lower()
	for obj in taut:
		if obj[0].lower() != letter:
			flag = 1
			break


	if flag == 0:
		print('Y')
	else:
		print('N')
