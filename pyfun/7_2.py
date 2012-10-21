#100% score
def equi(A):
	if len(A) == 0:
		return -1;
	total_sum = sum(A);
	sdleft = 0;
	for i in range(len(A)):
		sdright = total_sum - sdleft - A[i];
		if sdleft == sdright:
			return i;
		sdleft+=A[i];
	return -1

A = [-7, 1, 5, 2, -4, 3, 0]
#print min(A);
print equi(A);