import sys
sys.path.append('~/jobggle/py/eul_me.pyc')
import eul_me

for i in range(100):
	if eul_me.isprimeme(i) == True:
		print i;
