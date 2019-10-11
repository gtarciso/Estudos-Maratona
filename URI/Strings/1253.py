n = int(input())

for k in range(n):
	x = input()
	aux = ''
	y = int(input())
	for i in range(len(x)):
		num = ((ord(x[i]) - 65 - y) % 26) + 65
		aux += str(chr(num))

	print(aux)