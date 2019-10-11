n = int(input())

for i in range(n):
	text = input()
	a1 = 0
	a2 = 0
	w = 0
	sentry = 0
	for j in range(len(text)):
		if text[j] != 'a' and sentry == 1:
			w = 1

		if text[j] == 'a' and w == 0:
			sentry = 1
			a1 += 1

		if text[j] == 'a' and w == 1:
			a2 += 1


	kame = 'k'
	size = a1*a2
	for j in range(size):
		kame += 'a'

	print(kame)