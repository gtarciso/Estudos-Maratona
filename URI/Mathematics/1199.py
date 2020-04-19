while True:
	x = input()
	if x == "-1":
		break;
	if len(x) > 1:
		if x[1] == 'x':
			aux = x.split('x')
			d = int(aux[1], 16)
			print(d)
		else:
			aux = int(x)
			h = hex(aux)
			st = str(h).split('x')
			ans = '0x'+st[1].upper()
			print(ans)

	else:
		aux = int(x)
		h = hex(aux)
		st = str(h).split('x')
		ans = '0x'+st[1].upper()
		print(ans)