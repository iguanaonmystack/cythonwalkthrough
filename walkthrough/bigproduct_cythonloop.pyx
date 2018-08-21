
def bigproduct(digits, n=13):
    '''Return the biggest product of n consecutive digits'''
    cdef size_t i, j

    best = 0
    for i in range(len(digits) - (n - 1)):
        product = 1
        for j in range(n):
            product *= digits[i + j]
        if product > best:
            best = product
    return best

