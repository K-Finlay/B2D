#include "../B2D.h"
#include "Py.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This File Contains All Of The Python Input Functions                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace b2d{

	// Get The Mouse Position
	PyObject* Python::B2D_GetMousePos (PyObject* Self, PyObject* Args){

		// Set Variables
		Vector2::Point point;
		point = Input::GetMousePosition();

		return Py_BuildValue ("ii", (int) point.x, (int) point.y);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get Mouse Button Pressed
	PyObject* Python::B2D_GetMouseButton (PyObject* Self, PyObject* Args){

		// Create Variables
		int inputKey;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &inputKey)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

        Mouse newKey = static_cast <Mouse> (inputKey);

		// Set Function
		if (Input::GetMouseButton (newKey)){
			Py_RETURN_TRUE;
		}

		else{
			Py_RETURN_FALSE;
		}
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get Button Pressed
	PyObject* Python::B2D_GetKey (PyObject* Self, PyObject* Args){

		// Create Variables
		int inputKey;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &inputKey)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		Key newKey = static_cast <Key> (inputKey);
		
		// Set Function
		if (Input::GetKey (newKey)){
			Py_RETURN_TRUE;
		}

		else{
			Py_RETURN_FALSE;
		}
	}
}