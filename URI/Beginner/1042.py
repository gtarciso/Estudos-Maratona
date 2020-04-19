st = input().split()
so = []

for i in range(len(st)):
	so.append(int(st[i]))

so.sort()

for i in range(len(so)):
	print(so[i])

print("")

for i in range(len(st)):
	print(st[i])