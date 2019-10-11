n = int(input())

for i in range(n):
	text = input().split(' ')
	str1 = text[0]
	str2 = text[1]
	tam = len(str1)
	count = 0

	for j in range(tam):
		letter1 = ord(str1[j])-64
		letter2 = ord(str2[j])-64

		count += (letter2-letter1)%26


	print(count)

