n = int(input())

i = 0

while i < n:
	cont = 0
	diamonds = 0
	st = input()
	for j in range(len(st)):
		if st[j] == '<':
			cont += 1

		if st[j] == '>':
			if cont > 0:
				cont -= 1
				diamonds += 1
				
	i += 1
	print(diamonds)