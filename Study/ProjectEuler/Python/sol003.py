n=317584931803

def findpart(x):
	i=2
	while i<=x:
	if x%i==0:
		return i
	i=i+1

eld=False
while end==False:
	a=findpart(n)
	if a!=n:
		print a
		n=n/a
	else:
		print n
		end=True

