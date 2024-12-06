#include <Python.h>

static PyObject* print(PyObject *self, PyObject *args) 
{
    const char *name;
    if (!PyArg_ParseTuple(args, "s", &name)) 
    {
        return NULL;
    }
    
    printf("taskc, %s!\n", name);
    Py_RETURN_NONE;
}

static PyMethodDef taskMethods[] = 
{
    {"print", print, METH_VARARGS, "print inputs"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef taskmodule = 
{
    PyModuleDef_HEAD_INIT,
    "taskc", /* name of module */
    NULL,    /* module documentation */
    -1,      /* size of per-interpreter state */
    taskMethods
};

PyMODINIT_FUNC PyInit_taskc(void) 
{
    return PyModule_Create(&taskmodule);
}

