#include "../B2D.h"
#include "Py.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This File Contains All Of The Python Sound Functions                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace b2d{

	// Declare Variable
    std::vector <Sound> Python::soundList;

	// Create A New Sound
	PyObject* Python::B2D_CreateSound (PyObject* Self, PyObject* Args){

		// Create Variables
		char* fileName; bool looping; bool loadIntoMemory = true;

		 // Look For Errors
    	if (!PyArg_ParseTuple (Args, "sb|b", &fileName, &looping, &loadIntoMemory)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Create New Sound
        Sound sound (fileName, looping, loadIntoMemory);

		// Add Sound To List
        Python::soundList.push_back (sound);

		// Set Function
        return Py_BuildValue ("i", Python::soundList.size() - 1);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Play A Sound
	PyObject* Python::B2D_PlaySound (PyObject* Self, PyObject* Args){

		// Create Variables
		int soundReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &soundReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
        Python::soundList[soundReference].Play();
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Pause A Sound
	PyObject* Python::B2D_PauseSound (PyObject* Self, PyObject* Args){

		// Create Variables
		int soundReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &soundReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
        Python::soundList[soundReference].Pause();
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Stop A Sound
	PyObject* Python::B2D_StopSound (PyObject* Self, PyObject* Args){

		// Create Variables
		int soundReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &soundReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
        Python::soundList[soundReference].Stop();
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set Sound Volume
	PyObject* Python::B2D_SetSoundVolume (PyObject* Self, PyObject* Args){

		// Create Variables
		int soundReference; float volume;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "if", &soundReference, &volume)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
        Python::soundList[soundReference].SetVolume (volume);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set Sound Pan
	PyObject* Python::B2D_SetSoundPan (PyObject* Self, PyObject* Args){

		// Create Variables
		int soundReference; float pan;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "if", &soundReference, &pan)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
        Python::soundList[soundReference].SetPan (pan);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set Sound Pitch
	PyObject* Python::B2D_SetSoundPitch(PyObject* Self, PyObject* Args){

		// Create Variables
		int soundReference; float pitch;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "if", &soundReference, &pitch)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
        Python::soundList[soundReference].SetPitch (pitch);
		Py_RETURN_NONE;
	}
}
