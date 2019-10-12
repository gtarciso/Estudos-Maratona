text = input().split(' ')
e = int(text[0])
d = int(text[1])

if e > d or d > 25:
	print("Eu odeio a professora!")

elif e < d < 22:
	print("Muito bem! Apresenta antes do Natal!")

else:
	print("Parece o trabalho do meu filho!")
	final_date = e+2
	if final_date < 24:
		print("TCC Apresentado!")

	else:
		print("Fail! Entao eh nataaaaal!")