def hp_func(bs, iv, ev, lvl):
	evc = ev**(0.5)/8.0
	hpc = ((iv + bs + evc + 50)*lvl)/50 + 10
	return hpc

def s_func(bs, iv, ev, lvl):
	evc = ev**(0.5)/8.0
	sc = ((iv + bs + evc)*lvl)/50 + 5
	return sc


n = int(input())

for i in range(n):
	name_lvl = input().split(' ')
	hp = input().split(' ')
	at = input().split(' ')
	df = input().split(' ')
	sp = input().split(' ')
	lvl = int(name_lvl[1])
	name = name_lvl[0]

	hpc = int(hp_func(int(hp[0]), int(hp[1]), int(hp[2]), lvl))
	atc = int(s_func(int(at[0]), int(at[1]), int(at[2]), lvl))
	dfc = int(s_func(int(df[0]), int(df[1]), int(df[2]), lvl))
	spc = int(s_func(int(sp[0]), int(sp[1]), int(sp[2]), lvl))

	print('Caso #' + str(i+1) + ': ' + name + ' nivel ' + str(lvl))
	print('HP: ' + str(hpc))
	print('AT: ' + str(atc))
	print('DF: ' + str(dfc))
	print('SP: ' + str(spc))