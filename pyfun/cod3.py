
from varcon import *
def cnt(m):
	"""
	(int)->int
	returns the number of occurence of 1 in the binary representation of an integer
	"""
	total = 1
	while m > 1:
		f = m%2;
		#print f;
		if f == 1:
			total+=1
		else:
			pass
		m/=2;
	return total;

'''
print cnt(1000000)
print bin(1000000).count('1');
print bin(1000000)
print len(bin(1000000));
'''

def pow2bin(n):
	"""
	(int)-> str
	returns the string binary representation of 2**n

	"""
	return "0b1"+('0'*n);
	#return bin(2**n);

#print pow2bin(90)

def binadd(bin1, bin2):
	"""bin is the array of binary numbers to be added"""
	if bin1 == bin2:
		return bin1+"0";
	else:
		return bin(int(bin1, 2)+int(bin2, 2))

#print binadd('0b1000','0b1100')

def  bitcountInTripled(array):
	sm = '0b0';
	for element in array:
		sm = binadd(sm, pow2bin(element));
	g = 3*int(sm, 2);
	#print "int value", g;
	#print "bin rep", bin(g);
	return bin(g).count('1');

print bitcountInTripled(array100000)
#data set is a possible issue