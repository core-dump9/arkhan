#import fib

#print 
#fib.fib(67);
def foo():
    doc = "The foo property."
    def fget(self):
        return self._foo
    def fset(self, value)
        self._foo = value
    def fdel(self):
        del self._foo
    return locals()
foo = property(**foo())

print foo