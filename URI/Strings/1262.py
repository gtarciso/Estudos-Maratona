while 1:
	try:

		text = input()
		cores = int(input())
		clocks = 0
		reads = 0
		for i in range(len(text)):
			if text[i] == 'R':
				if reads == 0:
					clocks += 1
					
				reads = (reads + 1) % cores

			if text[i] == 'W':
				clocks += 1
				reads = 0

		print(clocks)

	except EOFError:
		break