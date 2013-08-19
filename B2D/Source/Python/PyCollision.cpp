#include "../B2D.h"
#include "Py.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This File Contains All Of The Python Collision Functions                                               //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace b2d{

	PyObject* Python::B2D_GetCollision (PyObject* Self, PyObject* Args){

		// Create Variables
		float startPointX, startPointY, endPointX, endPointY, startSizeX = 1.0f, startSizeY = 1.0f, endSizeX = 1.0f, endSizeY = 1.0f; int collisionType = 0;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ffff|ffffi", &startPointX, &startPointY, &endPointX, &endPointY, &startSizeX, &startSizeY, &endSizeX, &endSizeY, &collisionType)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		if (Collision::GetCollision (Vector2::Point (startPointX, startPointY), Vector2::Point (endPointX, endPointY),
			Vector2::Point (startSizeX, startSizeY), Vector2::Point (endSizeX, endSizeY), collisionType)){

			Py_RETURN_TRUE;
		}

		else{
			Py_RETURN_FALSE;
		}
	}
}