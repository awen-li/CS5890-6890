
#include <Python.h>
#include "analyzer.h"

static Analyzer *Anyz = NULL;

static PyObject *Init(PyObject *self, PyObject *args)
{
    char* FuncList;

    if (!PyArg_ParseTuple(args, "s", &FuncList))
	{
        Py_RETURN_NONE;
	}
	
	Anyz = new Analyzer (string (FuncList));
    assert (Anyz != NULL);

    Py_RETURN_NONE;
}

static int DeInit(PyObject* module)
{
    delete Anyz;
    return 0;
}

static PyObject *ReadShmQueue(PyObject *self, PyObject *args)
{
    assert (Anyz != NULL);

	Anyz->StartReadQueue ();
    Py_RETURN_NONE;
}

static PyObject *GetUncoeredFuncs(PyObject *self, PyObject *args) 
{
    assert (Anyz != NULL);

    std::string UncoeredFuncs = Anyz->GetUncoveredFuncs ();

    return Py_BuildValue("s", UncoeredFuncs.c_str());
}

static PyMethodDef AnlyzMethods[] = 
{
    {"Init",             Init, METH_VARARGS, "init before use"},
    {"ReadShmQueue",     ReadShmQueue, METH_VARARGS, "read data from shared queue"},
    {"GetUncoeredFuncs", GetUncoeredFuncs, METH_VARARGS, "pop uncovered functions"},
    {NULL, NULL, 0, NULL} 
};



static struct PyModuleDef ModAnalyzer = {
    PyModuleDef_HEAD_INIT,
    "analyzer",              /* Module name */
    "",                      /* Module documentation */
    -1,                      /* Module state size */
    AnlyzMethods,            /* Method table */
    NULL,                    /* Optional traverse function */
    NULL,                    /* Optional clear function */
    DeInit                   /* Cleanup function called during deinitialization */
};

PyMODINIT_FUNC PyInit_analyzer(void)
{
    return PyModule_Create(&ModAnalyzer);
}