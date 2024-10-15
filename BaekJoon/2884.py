Hour, Minutes = map(int, input().split())

if Minutes < 45:
	if Hour == 0:
		print(23, Minutes+15)
	else:
		print(Hour-1, Minutes+15)

else:
	print(Hour, Minutes-45)
