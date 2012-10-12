class Point:
   def __init__(self, x=0, y=0):
      self.x = x
      self.y = y
   
   def __del__(self):
      class_name = self.__class__.__name__
      print class_name, "destroyed"

k = Point(6, 7);
h = k;
p = h;

#print id(k), id(p), id(h);

if id(k) == id(p):
	print "same memory reference"

print id(k);