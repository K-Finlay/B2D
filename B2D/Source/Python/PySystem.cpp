#include "../B2D.h"
#include "Py.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This File Contains All Of The Python System Functions                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace b2d{

	// Get The Display Width
	PyObject* Python::B2D_GetDisplayWidth (PyObject* Self, PyObject* Args){

		// Set Function
		return Py_BuildValue ("i", System::GetDisplayWidth());
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get The Display Height
	PyObject* Python::B2D_GetDisplayHeight (PyObject* Self, PyObject* Args){

		// Set Function
		return Py_BuildValue ("i", System::GetDisplayHeight());
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get The Display Pixel Count
	PyObject* Python::B2D_GetDisplayPixels (PyObject* Self, PyObject* Args){

		// Set Function
		return Py_BuildValue ("i", System::GetDisplayPixels());
	}
}