class Set :
	def __init__(self):
		self._theElements = list();

	def __len__(self):
		return len(self._theElements);

	def __contains__(self, element):
		return element in self._theElements;

	def add(self, element):
		if element not in self :
			self._theElements.append(element);

	def remove(self):
		assert element in self, "Element does not exist in the set";
		self._theElements.remove(element);

	def __eq__(self, setB):
		if len(self) != len(setB):
			return False;
		else:
			return self.isSubsetof(setB);

	def isSubsetof(self, setB):
		for element in self:
			if element not in setB:
				return False;
			return True;
	def lister(self):
		tos = self._theElements;
		for i in tos:
			return i;
		pass


	def union(self, setB):
		newSet = Set();
		newSet._theElements.extend(self._theElements);
		for element in setB:
			if element not in self:
				newSet._theElements.append(element);
		return newSet;

	def intersect(self, setB):
		pass;

	def difference(self, setB):
		pass;

	def __iter__(self):
		return _SetIterator(self._theElements)
		