text = input()

vowels = ''

for i in range(len(text)):
	if text[i] == 'a' or text[i] == 'e' or text[i] == 'i' or text[i] == 'o' or text[i] == 'u':
		vowels += text[i]

equals = 0
tam = len(vowels)-1
middle = int(len(vowels)/2)
for i in range(middle):
	if vowels[i] != vowels[tam-i]:
		equals = 1

if equals == 0:
	print('S')
else:
	print('N')
