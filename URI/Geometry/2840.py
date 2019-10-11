pi = 3.1415

st = input().split(' ')
radius = int(st[0])
vol    = int(st[1])

vol_bal = 4.0/3.0 * pi*radius*radius*radius
amt = int(vol/vol_bal)
print(amt)
