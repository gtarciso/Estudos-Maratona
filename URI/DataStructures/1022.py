def mdc(a, b):
	if b == 0:
		return a
	else:
		return mdc(b, a % b)

n = int(input())
i = 0

while i < n:
	st = input()
	result = st.split(' ')
	d_num1 = 0
	n_num1 = 0
	d_num2 = 0
	n_num2 = 0
	n1 = int(result[0])
	n2 = int(result[4])
	d1 = int(result[2])
	d2 = int(result[6])

	if result[3] == '+':
		d_num1 = d1*d2
		n_num1 = n1*d2 + n2*d1

	if result[3] == '-':
		d_num1 = d1*d2
		n_num1 = n1*d2 - n2*d1

	if result[3] == '*':
		d_num1 = d1*d2
		n_num1 = n1*n2

	if result[3] == '/':
		d_num1 = n2*d1
		n_num1 = n1*d2

	x = mdc(n_num1, d_num1)
	print(str(n_num1) + '/' + str(d_num1) + " = " + str(int(n_num1/x)) + '/' + str(int(d_num1/x)))

	i += 1
