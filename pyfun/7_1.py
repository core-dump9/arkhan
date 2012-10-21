def ps (A):
    totalsum = sum(A);
    prev, curr = 0, A[0]
    if len(A) > 10000000:
        return -1;
    elif len(A) < 3:
        return -1
    else:
        for i in range(1, len(A)):
            prev+=A[i-1];
            curr+=A[i];
            if curr + prev == totalsum:
                return i;
        return -1;