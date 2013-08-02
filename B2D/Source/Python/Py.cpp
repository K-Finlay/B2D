#include "../B2D.h"
#include "Py.h"
#include <iostream>

// The Function Lookup Table
PyMethodDef b2d::Python::B2DFunctions[] = {

	{"CreateGameWindow", B2D_CreateGameWindow, METH_VARARGS, "Create The Game Window."},
	{"ClearScreen"     , B2D_ClearScreen     , METH_VARARGS, "Clear The Screen."      },
	{"CloseWindow"     , B2D_CloseWindow     , METH_VARARGS, "Close The Window."      },
	{"ToggleFullScreen", B2D_ToggleFullScreen, METH_VARARGS, "Toggle Full Screen."    },
	{"SetWindowSize"   , B2D_SetWindowSize   , METH_VARARGS, "Set The Window Size."   },
	{"SetWindowTitle"  , B2D_SetWindowTitle  , METH_VARARGS, "Set The Window Title."  },
	{"GameLoop"        , B2D_GameLoop        , METH_VARARGS, "The Game Loop."         },
	{NULL, NULL, 0, NULL}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Python Module Functions                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Functions Required To Load The Python Modules
void ParsePyTupleError (const char* Function, int Line){

	std::cout << "___Error Parsing Tuple___\nFunction : " <<  Function << "\nLine# : " << Line << std::endl;
	PyErr_Print();
}

// Import Python Module
PyObject* ImportPythonModule (const char* ModuleName){

	PyObject* objName = PyString_FromString (ModuleName);
	PyObject* module = PyImport_Import (objName);

	// Check If Module Exists
	if (!module){

		PyErr_Print();
        std::cout << stderr << "Failed to load \" " << ModuleName << "\"" << std::endl;
	}

	Py_DECREF (objName);
	return module;
}

// Get Handle To Python Function
PyObject* GetHandleToPythonFunction (PyObject* Module, const char* FunctionName){

    PyObject* function = PyObject_GetAttrString (Module, FunctionName);

	// Check For Error
	if (! (function && PyCallable_Check (function))){

		if (PyErr_Occurred()){
			PyErr_Print();
		}

		std::cout << stderr << "Cannot find function \"" << FunctionName << "\"" << std::endl;
	}

	return function;
}

// Call Python Function
PyObject* CallPythonFunction (PyObject* Function, PyObject* FunctionArguments){

	PyObject* returnValue = PyObject_CallObject (Function, FunctionArguments);

	// Check For Error
	if (returnValue == NULL){

		PyErr_Print();
		std::cout << stderr << "Call failed\n";
	}

	return returnValue;
}