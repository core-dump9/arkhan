def reset(array):
	gt = [];
	
	for i in range(len(array)/2):
			x = max(array);
			y = min(array);
			gt.append(y);
			gt.append(x);
			array.remove(y);
			array.remove(x);
	return gt;

f = [1, 2, 3, 4, 5]

print reset(f);