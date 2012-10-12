def isprimefast(n):
	t = list();
        for i in range(1, 6, 1):
               if n%i == 0:
                     t.append(i);
               else:
                     pass;
        if n<2 :
            return False;
        elif len(t) == 1:
            return True;
        else:
            return False;

print isprimefast(49979687);

#for s in range(50000):
#    if isprimefast(s):
#        print s;