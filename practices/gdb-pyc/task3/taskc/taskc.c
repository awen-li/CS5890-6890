#include <Python.h>

typedef struct _student_
{
    unsigned stuId;
    char stuName [32];
}STU;

static inline void getStuName (unsigned stuID, char** stuName)
{
    static STU allStudents[] = {{1, "alice"}, {2, "bob"}, {3, "jack"}, {5, "ami"}};

    for (unsigned i = 0; i < sizeof(allStudents)/sizeof(STU); i++)
    {
        if (stuID == allStudents[i].stuId)
        {
            *stuName = allStudents[i].stuName;
            break;
        }
    }

    return;
}

static PyObject* query(PyObject *self, PyObject *args) 
{
    int stuId = 0;
    
    if (!PyArg_ParseTuple(args, "i", &stuId)) 
    {
        return NULL;
    }
    
    char* stuName = NULL;
    getStuName (stuId, &stuName);
    
    return PyUnicode_FromString(stuName);
}

static PyMethodDef taskMethods[] = 
{
    {"query", query, METH_VARARGS, "query student name"},
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

