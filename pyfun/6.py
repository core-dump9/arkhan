import random;

def ps(a):
	s, a = [], list(a);
	y = [];
	if len(a) > 1000000:
		return -1;
	else:
		for i in a:
			if i not in s:
				s.append(i);
		y.append(a.index(s[-1]));
		return y[-1];

m = [2, 2, 1, 0, 1];
print ps(m)
