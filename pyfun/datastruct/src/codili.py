def equi(A):
	tot = len(A);
	#f = tot/2;
	listall = list();
	fhalf = list();
	shalf = list();
	for i in range(len(A)):
		fhalf = A[0:(tot-(i+1))];
		shalf = A[(tot-(i+1))::]
		#print shalf;
		#print fhalf;
		if sum(fhalf) == sum(shalf):
			listall.append(len(A)-(i+1));
	if len(listall) > 0:
		return listall;
	else:
		return -1;
"""
A[0] = -7   A[1] =  1   A[2] = 5
A[3] =  2   A[4] = -4   A[5] = 3
A[6] =  0
"""
testList = [-7, 1, 5, 2, -4, 3, 0]
a = [1, 2, 3, 3, 2, 1]
#print equi(testList)
print equi(testList);