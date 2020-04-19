
x = int(input())

for i in range(x):
	st = input().split()
	aux = 0
	if st[1] == '+':
		aux = int(st[0])+int(st[2])
	if st[1] == '-':
		aux = int(st[0])-int(st[2])
	if st[1] == 'x':
		aux = int(st[0])*int(st[2])

	er = aux - int(st[4])

	if er < 0:
		er = er*-1
	wr = "E"
	for i in range(er):
		wr += "r"

	wr+="ou!"

	print(wr)
