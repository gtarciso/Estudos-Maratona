n = int(input())

for i in range(n):
	x = int(input())
	regions = (x*(x+1))/2 + 1
	print(int(regions))