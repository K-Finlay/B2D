#include "../B2D.h"
#include "Py.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This File Contains All Of The Python Font Functions                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace b2d{

	// Declare Variable
	std::vector <Font> Python::fontList;

	// Create A New Font
	PyObject* Python::B2D_CreateFont(PyObject* Self, PyObject* Args){

		// Create Variables
		const char* fontPath; char* text; int size; float x; float y; char* colour = "ffffffff"; bool isStatic = false; int fontType = 0;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ssiff|sbi", &fontPath, &text, &size, &x, &y, &colour, &isStatic, &fontType)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		RGBA rgba = RGBA (colour);

		// Create New Font
		Font* font = new Font (fontPath, text, size, Vector2::Point (x, y), rgba, isStatic, fontType);

		// Add Font To List
		Python::fontList.push_back (*font);

		// Delete Old Font
		delete font;

		// Set Function
		return Py_BuildValue ("i", Python::fontList.size() - 1);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Draw The Font
	PyObject* Python::B2D_DrawFont (PyObject* Self, PyObject* Args){

		// Set Variables
		int fontReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &fontReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::fontList[fontReference].Draw();
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Move The Font
	PyObject* Python::B2D_MoveFont (PyObject* Self, PyObject* Args){

		// Set Variables
		int fontReference;
		float x, y;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iff", &fontReference, &x, &y)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::fontList[fontReference].Move (x, y);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Translate The Font
	PyObject* Python::B2D_TranslateFont (PyObject* Self, PyObject* Args){

		// Set Variables
		int fontReference;
		float x, y;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iff", &fontReference, &x, &y)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::fontList[fontReference].Translate (x, y);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Font Colour
	PyObject* Python::B2D_SetFontColour (PyObject* Self, PyObject* Args){

		// Set Variables
		int fontReference;
		char* colour;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "is", &fontReference, &colour)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		RGBA rgba = RGBA (colour);
		Python::fontList[fontReference].SetColour (rgba);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set Font Size
	PyObject* Python::B2D_SetFontSize (PyObject* Self, PyObject* Args){

		// Set Variables
		int fontReference, size;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ii", &fontReference, &size)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::fontList[fontReference].SetSize (size);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Destroy The Font
	PyObject* Python::B2D_DestroyFont (PyObject* Self, PyObject* Args){

		// Set Variables
		int fontReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &fontReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::fontList[fontReference].Destroy();

		// Remove From List
		Python::fontList.erase (Python::fontList.begin() + fontReference);
		Py_RETURN_NONE;
	}
}