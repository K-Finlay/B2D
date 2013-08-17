#include "../B2D.h"
#include "Py.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This File Contains All Of The Python Primitive Functions                                               //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace b2d{

	// Set Primitive Lists
	std::vector <Square> Python::primitiveSquareList;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Create A Square
	PyObject* Python::B2D_CreateSquare (PyObject* Self, PyObject* Args){

		// Create Variables
		float x, y; int width, height; char* colour = "FFFFFFFF";

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ffii|s", &x, &y, &width, &height, &colour)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		RGBA rgba = RGBA (colour);

		// Create New Square
		Square* square = new Square (Vector2::Point (x, y), width, height, rgba);

		// Add Square To List
		primitiveSquareList.push_back (*square);

		// Delete Square
		delete square;

		// Set Function
		Python::primitiveSquareList[Python::primitiveSquareList.size() - 1].Update();
		return Py_BuildValue ("i", Python::primitiveSquareList.size() - 1);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Draw The Square
	PyObject* Python::B2D_DrawSquare (PyObject* Self, PyObject* Args){

		// Create Variables
		int squareReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &squareReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::primitiveSquareList[squareReference].Draw();
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Move The Square
	PyObject* Python::B2D_MoveSquare (PyObject* Self, PyObject* Args){

		// Create Variables
		int squareReference; float x, y, rotation;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ifff", &squareReference, &x, &y, &rotation)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::primitiveSquareList[squareReference].Move (x, y, (double) rotation);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Translate The Square
	PyObject* Python::B2D_TranslateSquare (PyObject* Self, PyObject* Args){

		// Create Variables
		int squareReference; float x, y, rotation;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ifff", &squareReference, &x, &y, &rotation)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::primitiveSquareList[squareReference].Translate (x, y, (double) rotation);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Scale The Square
	PyObject* Python::B2D_ScaleSquare (PyObject* Self, PyObject* Args){

		// Create Variables
		int squareReference; float x, y;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iff", &squareReference, &x, &y)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::primitiveSquareList[squareReference].Scale (x, y);
		Py_RETURN_NONE;
	}
}