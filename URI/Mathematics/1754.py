n = int(input())
i = 0

while i < n:
	ent = input().split(' ')
	x = int(ent[0])
	y = int(ent[1])

	if x % y == 0:
		k = x/y
	else:
		k = x/y + 1

	if y > x:
		k = 2		

	print(int(k))
	i += 1