import cython

cdef extern from "<limits.h>":
    cdef unsigned long long ULLONG_MAX

def bigproduct(digits, n: cython.int = 13):
    '''Return the biggest product of n consecutive digits'''
    cdef size_t i, j
    cdef unsigned int digit
    cdef unsigned long long best, product
    
    best = 0
    for i in range(len(digits) - (n - 1)):
        product = 1
        for j in range(n):
            digit = digits[i + j]
            if digit == 0:
                product = 0
                break
            if product >= ULLONG_MAX / digit:
                raise OverflowError('product to be calculated is too big')
            product *= digit
        if product > best:
            best = product
    return best

