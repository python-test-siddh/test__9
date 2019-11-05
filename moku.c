#include <Python.h>
#include <stdio.h>

static PyObject *foo_bar(PyObject *self, PyObject *args)
{
const char *s;
Py_ssize_t size;
if (!PyArg_ParseTuple(args, ""))
return NULL;
return PyArg_ParseTuple(args);
}




static PyMethodDef FooMethods[] = {
{"moku",  foo_bar, METH_VARARGS},
{NULL, NULL}  /* Sentinel */
};

static struct PyModuleDef foo_bar_module = {
    PyModuleDef_HEAD_INIT,
    "moku",
    "Python interface for the fputs C library function",
    -1,
    FooMethods
};




PyMODINIT_FUNC PyInit_moku(void) {
    return PyModule_Create(&foo_bar_module);
}
