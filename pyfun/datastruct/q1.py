def reve(bits):
	c = bits[2::];
	d = "0b"+c[::-1];
	return d, int(d, 2);

o = bin(98);

print reve(o);