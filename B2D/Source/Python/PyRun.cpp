#include "../B2D.h"
#include "Py.h"
#include <iostream>

namespace b2d{

	// Initialize Python
	void Python::Init (const char* ScriptDirectory){

	    Py_Initialize();
	    PyObject* sysPath = PySys_GetObject ((char*) "path");
	    PyList_Append (sysPath, PyString_FromString (ScriptDirectory));
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Run Python Script
    void Python::RunScript (const char* PythonModule, const char* Function){
    
    	// Init Python
    	Py_InitModule ("b2d", B2DFunctions);
    
    	// Import Module
    	PyObject* module = ImportPythonModule (PythonModule);
    
    	// Check For Error
    	if (module != NULL){
    
    		// Check For Window Creation
    		PyObject* callFunction = GetHandleToPythonFunction (module, Function);
    		PyObject* functionReturnValue = CallPythonFunction (callFunction, NULL);
    
    		// Dereference Window Return
    		Py_DECREF (functionReturnValue);
    
    		// Dereference Create Window
    		Py_XDECREF (callFunction);
    	}
    }
}