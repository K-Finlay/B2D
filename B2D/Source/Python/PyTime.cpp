#include "../B2D.h"
#include "Py.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This File Contains All Of The Python Time Functions                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace b2d{

	// Get System Time
	PyObject* Python::B2D_GetSystemTime (PyObject* Self, PyObject* Args){

		// Create Variables
		int secMinHour;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &secMinHour)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		return Py_BuildValue ("d", Time::GetSystemTime (secMinHour));
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get The Delta Time
	PyObject* Python::B2D_GetDeltaTime (PyObject* Self, PyObject* Args){

		// Set Function
		Time::GetDeltaTime();
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Reset The Delta Time
	PyObject* Python::B2D_ResetDeltaTime (PyObject* Self, PyObject* Args){

		// Set Function
		Time::ResetDeltaTime();
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get The FPS
	PyObject* Python::B2D_GetFPS (PyObject* Self, PyObject* Args){

		// Set Function
		return Py_BuildValue ("d", Time::GetFPS());
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Return Delta Time
	PyObject* Python::B2D_deltaTime (PyObject* Self, PyObject* Args){

		// Set Function
		return Py_BuildValue ("f", (float) Time::deltaTime);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Wait For Seconds
	PyObject* Python::B2D_WaitForSeconds (PyObject* Self, PyObject* Args){

		// Create Variables
		double time;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "d", &time)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Time::WaitForSeconds (time);
		Py_RETURN_NONE;
	}
}