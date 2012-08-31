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

def reverse(string):
	return string[::-1];

def mydict(word):
	#this would contain the hash file of the words and definitions;
	dico = {"oldman":"An old man"} #get me words and stuff

	if type(word) != type('h'):
		return "That is not a word";
	else:
		try:
			dico[word]
		except KeyError, e:
			print "Word not in the dictionary"
			quit();
		else:
			print word.capitalize();
			print "================="
			print """Defined as :""",dico[word], """""";
			print "=================";
	return "!!!Query Complete!!!";