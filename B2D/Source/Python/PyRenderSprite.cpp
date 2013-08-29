#include "../B2D.h"
#include "Py.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This File Contains All Of The Python Sprite Functions                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace b2d{

	// Set Sprite List
	std::vector <Sprite> Python::spriteList;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Create A Sprite
	PyObject* Python::B2D_CreateSprite (PyObject* Self, PyObject* Args){

		// Create Variables
		float x, y; int width, height; char* texturePath, *colour = "FFFFFFFF";

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ffiis|s", &x, &y, &width, &height, &texturePath, &colour)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		RGBA rgba = RGBA (colour);

		// Create New Sprite
		Sprite sprite (Vector2::Point (x, y), width, height, texturePath, colour);

		// Add Sprite To List
		Python::spriteList.push_back (sprite);

		// Set Function
		return Py_BuildValue ("i", Python::spriteList.size() - 1);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Draw Sprite
	PyObject* Python::B2D_DrawSprite (PyObject* Self, PyObject* Args){

		// Create Variables
		int spriteReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &spriteReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
        Python::spriteList[spriteReference].Draw();
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Swap The Sprite Texture
	PyObject* Python::B2D_SwapSpriteTexture (PyObject* Self, PyObject* Args){

		// Create Variables
		int spriteReference; char* texturePath;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "is", &spriteReference, &texturePath)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::spriteList[spriteReference].SwapTexture (texturePath);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Play The Sprite Animation
	PyObject* Python::B2D_PlaySpriteAnimation (PyObject* Self, PyObject* Args){

		// Create Variables
		int spriteReference, numOfFrames, startNum, endNum; float animationSpeed;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iiiif", &spriteReference, &numOfFrames, &startNum, &endNum, &animationSpeed)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::spriteList[spriteReference].PlayAnimation (numOfFrames, startNum, endNum, animationSpeed);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Sprite Frame
	PyObject* Python::B2D_SetSpriteFrame (PyObject* Self, PyObject* Args){

		// Set Variables
		int spriteReference, numOfFrames, frame;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iii", &spriteReference, &numOfFrames, &frame)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::spriteList[spriteReference].SetFrame (numOfFrames, frame);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Stop The Animation
	PyObject* Python::B2D_StopSpriteAnimation (PyObject* Self, PyObject* Args){

		// Set Variables
		int spriteReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &spriteReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::spriteList[spriteReference].StopAnimation();
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Resume The Animation
	PyObject* Python::B2D_ResumeSpriteAnimation (PyObject* Self, PyObject* Args){

		// Set Variables
		int spriteReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &spriteReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::spriteList[spriteReference].ResumeAnimation();
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Reload The Sprite
	PyObject* Python::B2D_ReloadSprite (PyObject* Self, PyObject* Args){

		// Create Variables
		int spriteReference; float x, y; int width, height; char* texturePath, *colour = "FFFFFFFF";

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ffiis|s", &spriteReference, &x, &y, &width, &height, &texturePath, &colour)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		RGBA rgba = RGBA (colour);

		// Set Function
		Python::spriteList[spriteReference].Reload (Vector2::Point (x, y), width, height, texturePath, rgba);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Move The Sprite
	PyObject* Python::B2D_MoveSprite (PyObject* Self, PyObject* Args){

		// Create Variables
		int spriteReference; float x, y, rotation;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ifff", &spriteReference, &x, &y, &rotation)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::spriteList[spriteReference].Move (x, y, (double) rotation);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Translate The Sprite
	PyObject* Python::B2D_TranslateSprite (PyObject* Self, PyObject* Args){

		// Create Variables
		int spriteReference; float x, y, rotation;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ifff", &spriteReference, &x, &y, &rotation)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::spriteList[spriteReference].Translate (x, y, (double) rotation);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Scale The Sprite
	PyObject* Python::B2D_ScaleSprite (PyObject* Self, PyObject* Args){

		// Create Variables
		int spriteReference; float x, y;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iff", &spriteReference, &x, &y)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::spriteList[spriteReference].Scale (x, y);
		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get The Sprites Position
	PyObject* Python::B2D_GetSpritePosition (PyObject* Self, PyObject* Args){

		// Create Variables
		int spriteReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &spriteReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Return Position
		return Py_BuildValue ("ff", spriteList[spriteReference].position.x, spriteList[spriteReference].position.y);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Destroy The Sprite
	PyObject* Python::B2D_DestroySprite (PyObject* Self, PyObject* Args){

		// Create Variables
		int spriteReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "i", &spriteReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		Python::spriteList[spriteReference].Destroy();
		Py_RETURN_NONE;
	}
}
