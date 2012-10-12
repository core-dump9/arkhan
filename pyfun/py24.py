import eul_me

g = []
for s in range(100000000):
	if eul_me.isprimefast(s):
		g.append(s);

print sum(g);