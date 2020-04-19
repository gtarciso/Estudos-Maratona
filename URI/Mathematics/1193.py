n = int(input())

for i in range(n):
	st = input().split()
	print("Case "+str(i+1)+":")
	if st[1] == "dec":
		aux = int(st[0])
		h = hex(aux).split('x')
		b = bin(aux).split('b')
		print(str(h[1])+" hex")
		print(str(b[1])+" bin\n")

	if st[1] == "bin":
		aux = st[0]
		dec = 0
		pot = 1
		i = len(aux)-1
		while i >= 0:
			dec += int(aux[i])*pot 
			pot *= 2
			i -= 1 
		print(str(dec)+" dec")
		h = hex(dec).split('x')
		print(str(h[1])+" hex\n")

	if st[1] == "hex":
		aux = st[0]
		d = int(aux, 16)
		print(str(d)+" dec")
		b = bin(d).split('b')
		print(str(b[1])+" bin\n")