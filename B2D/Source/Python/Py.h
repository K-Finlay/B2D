#ifndef PY_H
#define PY_H

#include <Python.h>

#if defined (_WIN32)
    #define __func__ __FUNCTION__
#endif

// Functions Required To Load The Python Modules
void ParsePyTupleError (const char* Function, int Line);
PyObject* ImportPythonModule (const char* ModuleName);
PyObject* GetHandleToPythonFunction (PyObject* Module, const char* FunctionName);
PyObject* CallPythonFunction (PyObject* Function, PyObject* FunctionArguments);

namespace b2d{

	// This Is The Python Class
	class Python{
	public:

		// Functions
		static void Init (const char* ScriptDirectory);
		static void RunScript (const char* PythonModule, const char* Function);

		// Window Functions
		static PyObject* B2D_CreateGameWindow (PyObject* Self, PyObject* Args);
        static PyObject* B2D_ClearScreen (PyObject* Self, PyObject* Args);
        static PyObject* B2D_CloseWindow (PyObject* Self, PyObject* Args);
        static PyObject* B2D_ToggleFullScreen (PyObject* Self, PyObject* Args);
        static PyObject* B2D_SetWindowSize (PyObject* Self, PyObject* Args);
        static PyObject* B2D_SetWindowTitle (PyObject* Self, PyObject* Args);
        static PyObject* B2D_GameLoop (PyObject* Self, PyObject* Args);

	private:

		static PyMethodDef B2DFunctions[];
	};
}

#endif