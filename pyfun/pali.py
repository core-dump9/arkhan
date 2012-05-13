def rev(string):
	#string = str(raw_input());
	return string[::-1];

print ("enter the string/number to check");
string = str(raw_input());
if (string == (rev(string))):
	print ("a palindrome");
else:
	print ("not a palindrome");

##################################################
#	helios66				 #
#		.py				 #
##################################################
