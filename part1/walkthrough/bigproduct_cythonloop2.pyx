def bigproduct(digits, unsigned int n=13):
    cdef size_t i, j
    best = 0
    for i in range(len(digits) - (n - 1)):
        product = 1
        for j in range(n):
            product *= digits[i + j]
        if product > best:
            best = product
    return best
