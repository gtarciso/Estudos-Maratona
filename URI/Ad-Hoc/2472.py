text = input().split(' ')

l = int(text[0])
n = int(text[1])

m = l - n + 1

total = m * m + n - 1

print(int(total))