#include "../B2D.h"
#include "Py.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This File Contains All Of The Python Camera Functions                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace b2d{

    // Move The Camera
    PyObject* Python::B2D_MoveCamera (PyObject* Self, PyObject* Args){

		// Create Variables
		float x, y;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ff", &x, &y)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Camera::Move (x, y);
		Py_RETURN_NONE;
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Translate The Camera
	PyObject* Python::B2D_TranslateCamera (PyObject* Self, PyObject* Args){

		// Create Variables
		float x, y;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ff", &x, &y)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Camera::Translate (x, y);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Zoom The Camera
	PyObject* Python::B2D_ZoomCamera (PyObject* Self, PyObject* Args){

		// Create Variables
		float zoom;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "f", &zoom)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Camera::Zoom (zoom);
		Py_RETURN_NONE;
	}
}