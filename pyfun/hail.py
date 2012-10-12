from sys import *;
def hail(n):
	if n == 1:
		print 1;
	elif n > 1:
		if n % 2 == 0:
			print n;
			n = n/2;
			hail(n)
		else:
			print n
			n = (n*3)+1;
			hail(n);

def countcycle(i, j):
	count = []
	if i > 1 or i < j:
		if j <= i:
			quit();
		else:
			count.append(hail(j))

	return len(count)

print countcycle(1, 10)