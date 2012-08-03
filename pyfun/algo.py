#heapsort algorithm

def Parent(i):
	return i/2;

def Left(i):
	return 2*i;

def Right(i):
	return ((2*i)+1);

def Heapify(A, i, n):
	r = Right(i);
	l = Left(i);

	if l <= n and A[l] > A[i]:
		largest = 1;
	else:
		largest = i;
	if r <= n and A[r] > A[i]:
		largest = r;
	if largest != i:
		A[i], A[largest] = A[largest], A[i];
		Heapify(A, largest, n);

def Heaplength(A):
	return len(A)-1;

def BuildHeap(A):
	n = Heaplength(A);
	for i in range(n/2, 0,-1):
		Heapify(A, i, n);

def HeapSort(A):
	BuildHeap(A);
	HeapSize = Heaplength(A);
	for i in range(HeapSize,1, -1):
		A[1], A[i] = A[i], A[1];
		HeapSize=HeapSize-1;
		Heapify(A, 1, HeapSize);
	return A;
