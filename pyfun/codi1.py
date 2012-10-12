def che(string):
	"""
	che(string) tests a string and returns 1 if it is properly closed else -1
	"""
	try:
		assert len(string) < 200000 and len(string) > 1, "not allowed";
		string = str(string);
		f, b = list(), list();
		for s in string:
			y = string[(len(string) - 1)-string.index(s)];
			if s == "(" or y == ")":
				f.append(s);
				b.append(y);
		if (f.count("(")) == (b.count(")")):
			#print f.count('('), "counted f";
			#print b.count(')'), "counted b";
			return 1, f.count("("), b.count(")"), f, b;
		else:
			return -1, f.count("("), b.count(")"), f, b;
	except AssertionError, e:
		print "wrong use of method"

"""
s = open("pali.py", "r");
string = s.readlines();
#string = "(len(string) - 1)-string.index(s)"
for s in string:
	print str(s);
	print "-----------"
	print che(str(s));
"""
teststring = "(((((h)())))"
print che(teststring)[0];
#print che(teststring)[0];
#print teststring.count('(');
#print teststring.count(')');