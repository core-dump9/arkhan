def isprime(x):
	x = abs(int(x));
	if x < 2:
		return False;
	if x == 2:
		return True;
	if not x & 1:
		return False;
	
	for v in range(3, int(x**0.5)+1, 2):
		if x%v == 0:

			return False;
	return True;
