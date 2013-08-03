#ifndef PY_H
#define PY_H

#include <Python.h>
#include <vector>

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

		// Time Functions
		static PyObject* B2D_GetSystemTime (PyObject* Self, PyObject* Args);
		static PyObject* B2D_GetDeltaTime (PyObject* Self, PyObject* Args);
		static PyObject* B2D_ResetDeltaTime (PyObject* Self, PyObject* Args);
		static PyObject* B2D_GetFPS (PyObject* Self, PyObject* Args);
		static PyObject* B2D_deltaTime (PyObject* Self, PyObject* Args);

		// System Functions
		static PyObject* B2D_GetDisplayWidth (PyObject* Self, PyObject* Args);
		static PyObject* B2D_GetDisplayHeight (PyObject* Self, PyObject* Args);
		static PyObject* B2D_GetDisplayPixels (PyObject* Self, PyObject* Args);

		// Sound Functions
		static PyObject* B2D_CreateSound (PyObject* Self, PyObject* Args);
		static PyObject* B2D_PlaySound (PyObject* Self, PyObject* Args);
		static PyObject* B2D_PauseSound (PyObject* Self, PyObject* Args);
		static PyObject* B2D_StopSound (PyObject* Self, PyObject* Args);
		static PyObject* B2D_SetSoundVolume (PyObject* Self, PyObject* Args);
		static PyObject* B2D_SetSoundPan (PyObject* Self, PyObject* Args);
		static PyObject* B2D_SetSoundPitch (PyObject* Self, PyObject* Args);

	private:

		static PyMethodDef B2DFunctions[];
		static std::vector <Sound> soundList;
	};
}

#endif