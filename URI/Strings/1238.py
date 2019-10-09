n = int(input())

i = 0

while i < n:
	st = input()
	result = st.split(' ')
	st1 = result[0]
	st2 = result[1]
	n1 = len(st1)
	n2 = len(st2)
	m = n1
	final = ''
	if n2 < n1:
		m = n2

	j = 0;
	while j < m:
		final += st1[j]
		final += st2[j]
		j += 1

	while j < n1:
		final += st1[j]
		j += 1

	while j < n2:
		final += st2[j]
		j+=1

	i += 1

	print(final)