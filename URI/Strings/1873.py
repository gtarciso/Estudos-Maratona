n = int(input())

for i in range(n):
	st = input().split(' ')

	winner = -1
	j = 0
	k = 1
	if   st[j] == 'tesoura':
		if  st[k] == 'papel'   or st[k] == 'lagarto':
			winner = j
		else:
			winner = k
	elif st[j] == 'papel':
		if  st[k] == 'pedra'   or st[k] == 'spock':
			winner = j
		else:
			winner = k
	elif st[j] == 'pedra':
		if  st[k] == 'lagarto' or st[k] == 'tesoura':
			winner = j
		else:
			winner = k
	elif st[j] == 'lagarto':
		if st[k] == 'spock'    or st[k] == 'papel':
			winner = j
		else:
			winner = k
	elif st[j] == 'spock':
		if st[k] == 'tesoura'  or st[k] == 'pedra':
			winner == j
		else:
			winner = k

	if st[0] == st[1]:
		winner = -1

	if winner == -1:
		print('empate')
	elif winner == 1:
		print('sheldon')
	else:
		print('rajesh') 
