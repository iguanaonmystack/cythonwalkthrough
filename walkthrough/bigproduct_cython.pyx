import cython

cdef extern from "<limits.h>":
    cdef unsigned long long ULLONG_MAX

cdef unsigned long long MAX_MULTIPLICAND = ULLONG_MAX / 9

def bigproduct(digits, n: cython.int = 13):
    '''Return the biggest product of n consecutive digits'''
    cdef size_t i, j
    digit:cython.uint
    cdef unsigned long long best, product
    
    best = 0
    for i in range(len(digits) - (n - 1)):
        product = 1
        for j in range(n):
            if product >= MAX_MULTIPLICAND:
                raise OverflowError('product to be calculated is too big')
            digit = digits[i + j]
            product *= digit
        if product > best:
            best = product
    return best

