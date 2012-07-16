num = 400;

def negar(num) :
	if (num == 0) :
		return 1;
	else :
		return (num*(negar(num-1)));

print negar(num);