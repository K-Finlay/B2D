#include "../B2D.h"
#include "Py.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This File Contains All Of The Python GUI Button Functions                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace b2d{

	// Declare Variable
	std::vector <GUIButton> Python::guiButtonList;

	// Create GUI Button
	PyObject* Python::B2D_CreateGUIButton (PyObject* Self, PyObject* Args){

		// Create Variables
		float x, y; int width, height; char* texNorm, *texOver; char* colour = "ffffffff";

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ffiiss|s", &x, &y, &width, &height, &texNorm, &texOver, &colour)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		RGBA rgba = RGBA (colour);

		// Create New GUI Button
		GUIButton* button = new GUIButton (x, y, width, height, texNorm, texOver, rgba);

		// Add Button To List
		Python::guiButtonList.push_back (*button);

		// Delete Button
		delete button;

		// Set Function
		return Py_BuildValue ("i", Python::guiButtonList.size() - 1);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Move The Button
	PyObject* Python::B2D_MoveGUIButton (PyObject* Self, PyObject* Args){

		// Set Variables
		int guiButtonReference; float x, y, rotation;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ifff", &guiButtonReference, &x, &y, &rotation)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::guiButtonList[guiButtonReference].Move (x, y, (double) rotation);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Translate The Button
	PyObject* Python::B2D_TranslateGUIButton (PyObject* Self, PyObject* Args){

		// Set Variables
		int guiButtonReference; float x, y, rotation;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ifff", &guiButtonReference, &x, &y, &rotation)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::guiButtonList[guiButtonReference].Translate (x, y, (double) rotation);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Scale The Button
	PyObject* Python::B2D_ScaleGUIButton (PyObject* Self, PyObject* Args){

		// Set Variables
		int guiButtonReference; float x, y;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iff", &guiButtonReference, &x, &y)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::guiButtonList[guiButtonReference].Scale (x, y);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get Button Click
	PyObject* Python::B2D_GetGUIButtonClick (PyObject* Self, PyObject* Args){

		// Set Variables
		int guiButtonReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &guiButtonReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		return Py_BuildValue ("b", Python::guiButtonList[guiButtonReference].GetClick());
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get Mouse Over Button
	PyObject* Python::B2D_GetGUIButtonOver (PyObject* Self, PyObject* Args){

		// Set Variables
		int guiButtonReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &guiButtonReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		return Py_BuildValue ("b", Python::guiButtonList[guiButtonReference].GetOver());
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Draw The Button
	PyObject* Python::B2D_DrawGUIButton (PyObject* Self, PyObject* Args){

		// Create Variables
		int guiButtonReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &guiButtonReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::guiButtonList[guiButtonReference].Draw();
		Py_RETURN_NONE;
	}
}