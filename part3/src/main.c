#include <stdlib.h>
#include <stdio.h>

#include <Python.h>
#include "portal.h"

int main(int argc, char ** argv) {
    int result;
    printf("hello from C\n");
    if (PyImport_AppendInittab("portal", PyInit_portal) != 0) {
        fprintf(stderr, "Unable to extend Python inittab");
        return 1;
    }
    Py_Initialize();
    if (PyImport_ImportModule("portal") == NULL) {
        fprintf(stderr, "Unable to import cython module.\n");
        if (PyErr_Occurred()) {
            PyErr_PrintEx(0);
        } else {
            fprintf(stderr, "Unknown error");
        }
        return 1;
    }
    result = entrance(1, 2);
    if (result == -1 && PyErr_Occurred()) {
        fprintf(stderr, "Exception raised in portal()\n");
        PyErr_PrintEx(0);
    } else {
        printf("Result is %d\n", result);
    }
    Py_Finalize();
    return 0;
}
