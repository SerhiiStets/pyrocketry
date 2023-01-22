#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <math.h>

PyDoc_STRVAR(pyrocketry_doc, "Python module for rocket equations.");
PyDoc_STRVAR(pyrocketry_Tre_doc, "Tsiolkovsky rocket equation.");

static PyObject *PyrocketryError;

static PyObject *pr_Tre(PyObject *self, PyObject *args, PyObject *kwargs)
{
    double Isp = 0.0;  /* the specific impulse in dimension of time */
    double Mo = 0.0;   /* the initial total mass, including propellant, a.k.a. wet mass */
    double Mf = 0.0;   /* he final total mass without propellant, a.k.a. dry mass */
    float g = 9.80665; /* g - is an optional kwarg */
    double result;

    static char *kwlist[] = {"Isp", "Mo", "Mf", "g", NULL};
	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ddd|d", kwlist, &Isp, &Mo, &Mf, &g))
        return NULL;
    
    if (!Isp)
    {
        PyErr_SetString(PyrocketryError, "Isp. Specific Impulse can not be zero.");
        return NULL;
    } else if (!Mo)
    {
        PyErr_SetString(PyrocketryError, "Mo. Initial Total Wet Mass can not be zero.");
        return NULL;
    }

    result = Isp * g * log(Mo / Mf);
    return Py_BuildValue("d", result);
};

static PyMethodDef PyrocketryMethods[] = {
	{"Tre", (PyCFunction) pr_Tre, METH_VARARGS | METH_KEYWORDS, pyrocketry_Tre_doc},
	{NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef pyrocketrymodule= {
	PyModuleDef_HEAD_INIT,
	"pyrocketry",   /* name of the module */
	pyrocketry_doc, /* module documentation */
	-1,             /* size of per-interpreter state of the module,
                       or -1 if the module keeps state in global variables. */
    PyrocketryMethods	
};

PyMODINIT_FUNC PyInit_pyrocketry(void)
{
    PyObject *module;

    module = PyModule_Create(&pyrocketrymodule);
    if (module == NULL)
        return NULL;

    PyrocketryError = PyErr_NewException("pyrocketry.error", NULL, NULL);
    Py_XINCREF(PyrocketryError);
    if (PyModule_AddObject(module, "error", PyrocketryError) < 0) {
        Py_XDECREF(PyrocketryError);
        Py_CLEAR(PyrocketryError);
        Py_DECREF(module);
        return NULL;
    }

    return module;
}

int main(int args, char *argv[])
{
	wchar_t *program = Py_DecodeLocale(argv[0], NULL);
	if (program == NULL){
		fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
		exit(1);
	}

    /* Add a built-in module, before Py_Initialize */
	if (PyImport_AppendInittab("pyrocketry", PyInit_pyrocketry) == -1){
		fprintf(stderr, "Error: could not extend in-built modules table\n");
		exit(1);
	}
	
    /* Pass argv[0] to the Python interpreter */
	Py_SetProgramName(program);

    /* Initialize the Python interpreter.  Required.
       If this step fails, it will be a fatal error. */
	Py_Initialize();

    /* Optionally import the module; alternatively,
       import can be deferred until the embedded script
       imports it. */
	PyObject *pmodule = PyImport_ImportModule("pyrocketry");
	if (!pmodule) {
		PyErr_Print();
		fprintf(stderr, "Error, could not extend\n");
	}

	PyMem_RawFree(program);
	return 0;
}
