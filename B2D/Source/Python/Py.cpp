#include "../B2D.h"
#include "Py.h"
#include <iostream>

// The Function Lookup Table
PyMethodDef b2d::Python::B2DFunctions[] = {

	// Window Functions
	{"CreateGameWindow", B2D_CreateGameWindow, METH_VARARGS, "Create The Game Window."},
	{"ClearScreen"     , B2D_ClearScreen     , METH_VARARGS, "Clear The Screen."      },
	{"CloseWindow"     , B2D_CloseWindow     , METH_VARARGS, "Close The Window."      },
	{"ToggleFullScreen", B2D_ToggleFullScreen, METH_VARARGS, "Toggle Full Screen."    },
	{"SetWindowSize"   , B2D_SetWindowSize   , METH_VARARGS, "Set The Window Size."   },
	{"SetWindowTitle"  , B2D_SetWindowTitle  , METH_VARARGS, "Set The Window Title."  },
	{"GameLoop"        , B2D_GameLoop        , METH_VARARGS, "The Game Loop."         },

	// Time Functions
	{"GetSystemTime"   , B2D_GetSystemTime   , METH_VARARGS, "Get The System Time"    },
	{"GetDeltaTime"    , B2D_GetDeltaTime    , METH_VARARGS, "Get The Delta Time"     },
	{"ResetDeltaTime"  , B2D_ResetDeltaTime  , METH_VARARGS, "Reset The Delta Time"   },
	{"GetFPS"          , B2D_GetFPS          , METH_VARARGS, "Get The FPS"            },
	{"deltaTime"       , B2D_deltaTime       , METH_VARARGS, "Return The Delta Time"  },

	// System Functions
	{"GetDisplayWidth" , B2D_GetDisplayWidth , METH_VARARGS, "Get The Display Width"  },
	{"GetDisplayHeight", B2D_GetDisplayHeight, METH_VARARGS, "Get The Display Height" },
	{"GetDisplayPixels", B2D_GetDisplayPixels, METH_VARARGS, "Get The Display Pixels" },

	// Sound Functions
	{"CreateSound"     , B2D_CreateSound     , METH_VARARGS, "Create A New Sound"     },
	{"PlaySound"       , B2D_PlaySound       , METH_VARARGS, "Play A Sound"           },
	{"PauseSound"      , B2D_PauseSound      , METH_VARARGS, "Pause A Sound"          },
	{"StopSound"       , B2D_StopSound       , METH_VARARGS, "Stop A Sound"           },
	{"SetSoundVolume"  , B2D_SetSoundVolume  , METH_VARARGS, "Set Sound Volume"       },
	{"SetSoundPan"     , B2D_SetSoundPan     , METH_VARARGS, "Set Sound Pan"          },
	{"SetSoundPitch"   , B2D_SetSoundPitch   , METH_VARARGS, "Set Sound Pitch"        },
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