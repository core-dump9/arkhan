import ctypes;
"""Abstract Datatype implementation of an array in python using ctypes[a module to use C data types in python
"""
class Array:
	def __init__(self, size):
		assert size > 0, "Error, arrays size must be greater than 0";
		self._size = size;
		#Create the array structure using the ctypes module;
		PyArrayType = ctypes.py_object * self.size;
		self._elements = PyArrayType();
		#initialize each _elements
		self.clear(None);

	def __len__(self):
		return self._size;

	def __getitem__(self, index):
		assert index >= 0 and index < len(self), "Array index out of bounds";
		return self._elements[index]
	
	def __setitem__(self, index, value):
		assert index >= 0  and index < len(self), "Array subscript out of range";
		return self._elements[index];

	def clear(self, value):
		for i in range(len(self)):
			self._elements[i] = value;

	def __iter__(self):
		return _ArrayIterator(self._elements);

class _ArrayIterator():

	def __init__(self, theArray):
	 	self._arrayRef = theArray;
	 	self._curNdx = 0;

	def __iter__(self):
		return self;
		
	def __next__(self):
		if self._curNdx < len(self._arrayRef):
			entry = self._arrayRef[self._curNdx];
			self._curNdx += 1;
			return entry;
		else :
			raise StopIteration;