n = 2;
lx = [];
root = 3.40;
x = [];
fx = [];
px = 0;

for i in range(n):
	for j in range(n):
		if i!=j:
			lx[i]*=((root-x[j])/(x[i]-x[j]));
	px+=(lx[i]*fx[i]);

print px;