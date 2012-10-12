import binascii

def str_to_bin(string):
    return bin(int(binascii.hexlify(string), 16));

def bin_to_str(binary):
    if binary[0:2] == '0b':
        n = int(binary, 2);
        return binascii.unhexlify('%x' % n);
    else:
        n = int('0b'+binary, 2);
        return binascii.unhexlify('%x' % n);
'''
string = "010011010110100101110011011100110010000001100001011101000110111101101101011010010110001100100000011000100110111101101101011000100010110000100000011011010110111101110110011010010110111001100111001000000110111101101110001000000111011101100101001001110111011001100101001000000110011101101111011101000010000001110100011010000110010100100000011100100110000101100100011010010110111100100000011011110110111000101110001000000101100101101111011101010010011101110010011001010010000001100111011011110110111001101110011000010010000001101101011010010111001101110011001000000110110101100101001000000111011101101000011001010110111000100000011010010010011101101101001000000110011101101111011011100110010100101110"

print bin_to_str(string)
'''
def isprimefast(n):
	t = list();
        for i in range(1, 11, 1):
               if n%i == 0:
                     t.append(i);
               else:
                     pass;
        if n<2 :
            return False;
        elif t == [1] and len(t) == 1:
            return True;
        else:
            return False;

def isprime(n):
	t = list();
        for i in range(1, 6, 1):
               if n%i == 0:
                     t.append(i);
               else:
                     pass;
        if n<2 :
            return False;
        elif len(t) == 1 and t == [1]:
            return True;
        else:
            return False;


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