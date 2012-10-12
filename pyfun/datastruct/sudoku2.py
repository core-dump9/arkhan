from sys import exit, argv
def r(a):
  i = a.find('0')
  if i == -1:
    exit(a)
  for m in '3814697265625':
    okay = True
    for j in range(81):
      if (i-j)%9 == 0 or (i/9 == j/9) or (i/27 == j/27 and i%9/3 == j%9/3):
        if a[j] == m:
          okay = False
          break
    if okay:
      # At this point, m is not excluded by any row, column, or block, so let's place it and recurse
      r(a[:i]+m+a[i+1:])

r(argv[1])
