import sys

sys.path.insert(0, '.')
import mypythonmodule

cdef public int entrance(int a, int b) except? -1:
    print('hello from cython')
    return mypythonmodule.accumulate(a, b)
