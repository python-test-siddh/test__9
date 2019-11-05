#include <Python.h>
#include <stdio.h>



static PyObject *foo_bar(PyObject *self, PyObject *args)
{
PyObject *bufobj; 
    Py_buffer view; 
  
    /* Get the passed Python object */
    if (!PyArg_ParseTuple(args, "O", &bufobj)) 
    { 
        return NULL; 
    } 
  
    /* Attempt to extract buffer information from it */
  
    if (PyObject_GetBuffer(bufobj, &view, 
                           PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1) 
    { 
        return NULL; 
    } 
  
    if (view.ndim != 1) 
    { 
        PyErr_SetString(PyExc_TypeError, "Expected a 1-dimensional array"); 
        PyBuffer_Release(&view); 
        return NULL; 
    } 
  
    /* Check the type of items in the array */
    if (strcmp(view.format, "d") != 0) 
    { 
        PyErr_SetString(PyExc_TypeError, "Expected an array of doubles"); 
        PyBuffer_Release(&view); 
        return NULL; 
    } 
  
    /* Pass the raw buffer and size to the C function */
   
  
    /* Indicate we're done working with the buffer */
    PyBuffer_Release(&view); 
    return Py_BuildValue("d", 0.00000000000000000000000000000000000000000000000001); 
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
