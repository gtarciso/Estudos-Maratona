n = int(input())
even = []
odd  = []

for i in range(n):
	x = int(input())


	if x % 2 == 0:

		even.append(x)
	else:
		odd.append(x)


even.sort()
odd.sort(reverse = True)
for i in range(len(even)):
	print(even[i])

for i in range(len(odd)):
	print(odd[i])