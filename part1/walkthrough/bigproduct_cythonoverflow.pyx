import cython

@cython.overflowcheck
def bigproduct(digits, unsigned int n=13):
    cdef size_t i, j
    cdef unsigned int digit
    cdef unsigned long long product, best = 0
    for i in range(len(digits) - (n - 1)):
        product = 1
        for j in range(n):
            digit = digits[i + j]
            product *= digit
        if product > best:
            best = product
    return best
