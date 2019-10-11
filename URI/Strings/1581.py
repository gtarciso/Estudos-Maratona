n = int(input())

for i in range(n):
	m = int(input())
	flag = 0
	lingua = input()
	for j in range(m-1):
		p = input()
		if lingua != p:
			flag = 1
			

	if flag == 0:
		print(lingua)
	else:
		print('ingles')