def div(nm, di):
	if nm < di:
		#return sum;
		#pass;
		print "remainder", nm;
	else:
		print nm;
		nm = nm - di;
		div(nm, di);
	#return sm;

print div(6, 2)