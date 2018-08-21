#include <Python.h>

#include <limits.h>

/* For checking for impending overflow;
 * overly cautious but avoids switching on the multiplier */
unsigned long long MAX_MULTIPLICAND = ULLONG_MAX / 9;

static PyObject *
cbigproduct_bigproduct(PyObject *self, PyObject *args, PyObject *kw)
{
    char *keywords[] = {"digits", "n", NULL};
    PyObject *digits;
    int n = 13;
    Py_ssize_t digits_len;
    size_t i;
    unsigned long long best = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kw, "O|i", keywords, &digits, &n)) {
        return NULL;
    }

    if (!PySequence_Check(digits)) {
        PyErr_SetString(PyExc_TypeError, "digits is not a sequence");
        return NULL;
    }
    
    if ((digits_len = PySequence_Length(digits)) == -1) {
        return NULL;
    }

    for (i = 0; i < (digits_len - (n - 1)); i ++) {
        size_t j;
        unsigned long long product = 1;
        for (j = 0; j < n; j ++) {
            PyObject * py_digit;
            unsigned long digit;
            if (product >= MAX_MULTIPLICAND) {
                PyErr_SetString(PyExc_OverflowError,
                                "product to be calculated is too big");
                return NULL;
            }
            if ((py_digit = PySequence_GetItem(digits, i + j)) == NULL) {
                return NULL;
            }
            if (!PyLong_Check(py_digit)) {
                PyErr_SetString(PyExc_TypeError, "digit was not an integer");
            }
            digit = PyLong_AsUnsignedLong(py_digit);
            if (digit == (unsigned long)-1 && PyErr_Occurred()) {
                return NULL;
            }
            product *= digit;
        }
        if (product > best) {
            best = product;
        }
    }

    return PyLong_FromUnsignedLongLong(best);
}

static PyMethodDef CbigproductMethods[] = {
    {"bigproduct",
     (PyCFunction)cbigproduct_bigproduct,
     METH_VARARGS | METH_KEYWORDS,
     "Return the biggest product of n consecute digits"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef cbigproductmodule = {
    PyModuleDef_HEAD_INIT,
    "cbigproduct",   /* name of module */
    NULL,     /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    CbigproductMethods
};

PyMODINIT_FUNC
PyInit_cbigproduct(void)
{
    return PyModule_Create(&cbigproductmodule);
}
