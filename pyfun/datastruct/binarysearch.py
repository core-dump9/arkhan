def binsearch(a, value):
	lo = 0;
	hi = len(a);
	while (lo<=hi):
		i = (lo+hi)/2;
		if a[i] < value:
			lo = i+1;
		elif value < a[i]:
			hi = i-1;
		else:
			return i;
	return -1; #not in list;

ar = [1, 2, 3, 4, 5];
print binsearch(ar, 4);