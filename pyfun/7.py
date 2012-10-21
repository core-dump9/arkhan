##gave a 63 of 100
"""
def ps (A):
    totalsum = sum(A);
    prev, curr = 0, A[0]
    if len(A) > 10000000:
        return -1;
    else:
        for i in range(1, len(A)):
            prev+=A[i-1];
            curr+=A[i];
            if curr + prev == totalsum:
                return i;
        return -1;
#think of a better algorithm
"""

def equi(A):
    #sda = 0;
    #sdb = 0;
    length = len(A);
    maximum = max(A);
    minumum = min(A);
    try:
        assert (length < 10000000 and length > 1) and (minumum > -2147483648 and maximum < 2147483648);
        for i in range(length):
            sda = sum(A[:i+1])
            sdb = sum(A[i+2::])
            if sda == sdb:
                return i+1;
        return -1;
    except AssertionError, e:
        return -1

A = [-7, 1, 5, 2, -4, 3, 0]
#print min(A);
#print ps(A);
print ps(range(40000000));