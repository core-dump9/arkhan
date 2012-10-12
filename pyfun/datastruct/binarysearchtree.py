def fib(f):
	"""
	Docs string for the function
	"""
	a, b = 1, 1;
	while a < f:
		print a;
		a, b = b, a+b;

print fib(4)