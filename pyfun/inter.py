def uniq(f):
	ar = [];
	for s in f:
		if s not in ar:
			ar.append(s);

	return ar

s = [1, 2, 4, 5, 6, 6, 7, 9, 0, 1, 3, 2]

print (len(s), uniq(s), len(uniq(s)));