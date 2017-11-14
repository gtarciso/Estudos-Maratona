def fac (n):
	if n == 1 or n == 0:
		return 1
	else:
		return n*fac(n-1)

while True:
	try:
		p1, p2 = input().split()
		n1 = int(p1)
		n2 = int(p2)
		print(fac(n1)+fac(n2))
	except EOFError:
		break