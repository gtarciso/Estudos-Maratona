n = int(input())

i = 0
while i < n:
	st = input()
	if len(st) % 2 == 0:
		middle = int(len(st)/2)-1
	else:
		middle = int(len(st)/2)
	nova = ''
	j = middle
	while j >= 0:
		nova += st[j]
		j -= 1

	j = len(st)-1
	while j > middle:
		nova += st[j]
		j -= 1
	print(nova)

	i += 1