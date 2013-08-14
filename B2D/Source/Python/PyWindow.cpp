#include "../B2D.h"
#include "Py.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This File Contains All Of The Python Window Functions                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace b2d{
	
    // Create Game Window
    PyObject* Python::B2D_CreateGameWindow (PyObject* Self, PyObject* Args){
    
    	// Create Variables
    	int screenWidth; int screenHeight; char* windowTitle; bool fullScreen; int antiAlias = 0; bool vSync = false;
    
    	// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iisb|ib", &screenWidth, &screenHeight, &windowTitle, &fullScreen, &antiAlias, &vSync)){
    		ParsePyTupleError (__func__, __LINE__);
    	}
    
    	// Set Function
    	Window::CreateGameWindow (screenWidth, screenHeight, windowTitle, fullScreen, antiAlias, vSync);
    	Py_RETURN_NONE;
    }
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // Clear Screen
    PyObject* Python::B2D_ClearScreen (PyObject* Self, PyObject* Args){
    
    	// Create Variables
    	char* colourChar = "536878FF";
    
    	// Look For Errors
    	if (!PyArg_ParseTuple (Args, "|s", &colourChar)){
    		ParsePyTupleError (__func__, __LINE__);
    	}
    
    	RGBA colour = RGBA (colourChar);
    
    	// Set Function
    	Window::Clear (colour);
    	Py_RETURN_NONE;
    }
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // Close Window
    PyObject* Python::B2D_CloseWindow (PyObject* Self, PyObject* Args){
    
    	Window::Close();
    	Py_RETURN_NONE;
    }
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // Toggle Full Screen
    PyObject* Python::B2D_ToggleFullScreen (PyObject* Self, PyObject* Args){
    
    	// Create Variables
    	bool fullScreen;
    
    	// Look For Errors
    	if (!PyArg_ParseTuple (Args, "b", &fullScreen)){
    		ParsePyTupleError (__func__, __LINE__);
    	}
    
    	// Set Function
    	Window::ToggleFullScreen (fullScreen);
    	Py_RETURN_NONE;
    }
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // Set Window Size
    PyObject* Python::B2D_SetWindowSize (PyObject* Self, PyObject* Args){
    
    	// Create Variables
    	int width, height;
    
    	// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ii", &width, &height)){
    		ParsePyTupleError (__func__, __LINE__);
    	}
    
    	// Set Function
    	Window::SetSize (width, height);
    	Py_RETURN_NONE;
    }
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // Set Window Title
    PyObject* Python::B2D_SetWindowTitle (PyObject* Self, PyObject* Args){
    
    	// Create Variables
    	char* title;
    
    	// Look For Errors
    	if (!PyArg_ParseTuple (Args, "s", &title)){
    		ParsePyTupleError (__func__, __LINE__);
    	}
    
    	// Set Function
    	Window::SetTitle (title);
    	Py_RETURN_NONE;
    }
    
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // Game Loop
    PyObject* Python::B2D_GameLoop (PyObject* Self, PyObject* Args){
    
    	// Set Function
    	if (GameLoop()){
    	    Py_RETURN_TRUE;
		}

		else{
			Py_RETURN_FALSE;
		}
    }
}