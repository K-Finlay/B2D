#include "../B2D.h"
#include "Py.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This File Contains All Of The Python Particle Effect Functions                                         //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace b2d{

	// Set Particle Lists
	std::vector <ParticleEmitterPoint> Python::particlePointList;
	std::vector <ParticleEmitterLine> Python::particleLineList;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Create The Point Particle Emitter
	PyObject* Python::B2D_CreateParticleEmitterPoint (PyObject* Self, PyObject* Args){

		// Create Variables
		float x, y; char* texturePath; float fadeRate; char* colour = "ffffffff";

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ffsf|s", &x, &y, &texturePath, &fadeRate, &colour)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		RGBA rgba = RGBA (colour);

		// Create New Particle Emitter
		ParticleEmitterPoint* emitter = new ParticleEmitterPoint (Vector2::Point (x, y), texturePath, fadeRate, rgba);

		// Add Emitter To List
		Python::particlePointList.push_back (*emitter);

		// Delete Emitter
		delete emitter;

		// Set Function
		return Py_BuildValue ("i", Python::particlePointList.size() - 1);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Create The Line Particle Emitter
	PyObject* Python::B2D_CreateParticleEmitterLine (PyObject* Self, PyObject* Args){

		// Create Variables
		float startX, startY, endX, endY; char* texturePath; float fadeRate; char* colour = "ffffffff";

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ffffsf|s", &startX, &startY, &endX, &endY, &texturePath, &fadeRate, &colour)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		RGBA rgba = RGBA (colour);

		// Create New Particle Emitter
		ParticleEmitterLine* emitter = new ParticleEmitterLine (Vector2::Point (startX, startY), Vector2::Point (endX, endY), texturePath, fadeRate, rgba);

		// Add Emitter To List
		Python::particleLineList.push_back (*emitter);

		// Delete Emitter
		delete emitter;

		// Set Function
		return Py_BuildValue ("i", Python::particleLineList.size() - 1);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Emission Rate
	PyObject* Python::B2D_SetEmissionRate (PyObject* Self, PyObject* Args){

		// Create Variables
		int particleType, particleReference; float emissionRate; int emissionNumber;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iifi", &particleType, &particleReference, &emissionRate, &emissionNumber)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		if (particleType == 0){
		    Python::particlePointList[particleReference].SetEmissionRate (emissionRate, emissionNumber);
		}

		else {
			Python::particleLineList[particleReference].SetEmissionRate (emissionRate, emissionNumber);
		}

		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set Max Particles
	PyObject* Python::B2D_SetMaxParticles (PyObject* Self, PyObject* Args){

		// Create Variables
		int particleType, particleReference, maxParticles;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iii", &particleType, &particleReference, &maxParticles)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		if (particleType == 0){
		    Python::particlePointList[particleReference].SetMaxParticles (maxParticles);
		}

		else{
			Python::particleLineList[particleReference].SetMaxParticles (maxParticles);
		}

		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set Particle Health
	PyObject* Python::B2D_SetParticleHealth (PyObject* Self, PyObject* Args){

		// Create Variables
		int particleType, particleReference; float minHealth, maxHealth;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iiff", &particleType, &particleReference, &minHealth, &maxHealth)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		if (particleType == 0){
		    Python::particlePointList[particleReference].SetParticleHealth (minHealth, maxHealth);
		}

		else{
			Python::particleLineList[particleReference].SetParticleHealth (minHealth, maxHealth);
		}

		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set Particle Size
	PyObject* Python::B2D_SetParticleSize (PyObject* Self, PyObject* Args){

		// Create Variables
		int particleType, particleReference; float minSize, maxSize;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iiff", &particleType, &particleReference, &minSize, &maxSize)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		if (particleType == 0){
		    Python::particlePointList[particleReference].SetParticleSize (minSize, maxSize);
		}

		else{
			Python::particleLineList[particleReference].SetParticleSize (minSize, maxSize);
		}

		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set Particle Velocity
	PyObject* Python::B2D_SetParticleVelocity (PyObject* Self, PyObject* Args){

		// Create Variables
	    int particleType, particleReference; float minX, minY, maxX, maxY;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iiffff", &particleType, &particleReference, &minX, &minY, &maxX, &maxY)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		if (particleType == 0){
		    Python::particlePointList[particleReference].SetParticleVelocity (Vector2::Point (minX, minY), Vector2::Point (maxX, maxY));
		}

		else{
			Python::particleLineList[particleReference].SetParticleVelocity (Vector2::Point (minX, minY), Vector2::Point (maxX, maxY));
		}

		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Change Particle Velocity
	PyObject* Python::B2D_ChangeParticleVelocity (PyObject* Self, PyObject* Args){

		// Create Variables
	    int particleType, particleReference; float minX, minY, maxX, maxY;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iiffff", &particleType, &particleReference, &minX, &minY, &maxX, &maxY)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		if (particleType == 0){
		    Python::particlePointList[particleReference].ChangeParticleVelocity (Vector2::Point (minX, minY), Vector2::Point (maxX, maxY));
		}

		else{
			Python::particleLineList[particleReference].ChangeParticleVelocity (Vector2::Point (minX, minY), Vector2::Point (maxX, maxY));
		}

		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Draw The Particles
	PyObject* Python::B2D_DrawParticle (PyObject* Self, PyObject* Args){

		// Create Variables
		int particleType, particleReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ii", &particleType, &particleReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		if (particleType == 0){
			Python::particlePointList[particleReference].Draw();
		}

		else{
			Python::particleLineList[particleReference].Draw();
		}

		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Destroy The Particle
	PyObject* Python::B2D_DestroyParticle (PyObject* Self, PyObject* Args){

		// Create Variables
		int particleType, particleReference;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ii", &particleType, &particleReference)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		if (particleType == 0){

			Python::particlePointList[particleReference].Destroy();

			// Remove From List
			Python::particlePointList.erase (Python::particlePointList.begin() + particleReference);
		}

		else{

			Python::particleLineList[particleReference].Destroy();

			// Remove From List
			Python::particleLineList.erase (Python::particleLineList.begin() + particleReference);
		}

		Py_RETURN_NONE;
	}
}