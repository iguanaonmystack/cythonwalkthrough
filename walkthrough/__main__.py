import sys
import timeit
import platform
import importlib

if platform.python_implementation() == 'PyPy':
    sys.path.insert(0, '.')


def load_data(filename):
    digits = []
    for b in open(filename, 'rb').read():
        b = int(b)
        digits.append(b >> 4)
        digits.append(b & 0xf)
    return digits


if __name__ == '__main__':
    digits = load_data(sys.argv[1])

    for module in (
        'bigproduct',
        'bigproductx',
        'bigproduct_cythonloop',
        'bigproduct_cythonloop_annotations',
        'bigproduct_cython',
        'cbigproduct'
    ):
        bpmod = importlib.import_module('walkthrough.' + module)
        bigproduct = bpmod.bigproduct
        time = timeit.timeit(
            'bigproduct(digits)', number=1000, globals=globals())
        print(bigproduct(digits), time, module)

