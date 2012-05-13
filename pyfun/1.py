#welcome to the end
rangelist = range(10);

for number in rangelist:
	if number in (3, 4, 7, 9):
		break;
	else:
		continue;
else:
	pass;

if rangelist[1] == 1:
	print "The second item (lists are 0-based) is 1";
elif rangelist[1] == 3:
	print "The second item (lists are zero based) is 3";
else:
	print "Dunno";

while rangelist[1] == 4:
	pass
