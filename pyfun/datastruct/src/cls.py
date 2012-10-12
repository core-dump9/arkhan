class Test:
	def __init__(self, year):
		self.year = year;

	def prow(self):
		print self.year;

	def prows(self, cr):
		print self.year * cr;

#h = Test(6);

Test(8).prows(8);