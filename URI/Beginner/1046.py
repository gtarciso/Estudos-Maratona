x = input().split()

a = int(x[0])
b = int(x[1])

if a < b:
	print("O JOGO DUROU "+str(b-a)+" HORA(S)")
if a > b:
	print("O JOGO DUROU "+str(24-a+b)+" HORA(S)")
if a == b:
	print("O JOGO DUROU 24 HORA(S)")