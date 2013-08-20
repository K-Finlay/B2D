#include "../B2D.h"
#include "Py.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This File Contains All Of The Python Path Finding Functions                                            //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace b2d{

	std::vector <PathFinder> Python::pathList;
	std::vector <Node> Python::nodeList;
	std::vector <int> TupleToVector (PyObject* Incoming);

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Create New Path Finder
	PyObject* Python::B2D_CreatePathFinder (PyObject* Self, PyObject* Args){

		// Create New Path Finder
		PathFinder* path = new PathFinder;

		// Add To List
		pathList.push_back (*path);

		// Delete Old Path
		delete path;

		// Return Value
		return Py_BuildValue ("i", pathList.size() - 1);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Add Node To Path Finder
	PyObject* Python::B2D_PathFinderAddNode (PyObject* Self, PyObject* Args){

		// Create Variables
		int x, y; bool isWalkable;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iib", &x, &y, &isWalkable)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Create New Node
		Node* node = new Node;

		// Set Node Variables
		node[0].x = x;
		node[0].y = y;
		node[0].isWalkable = isWalkable;
		node[0].isChecked = false;
		node[0].listPos = nodeList.size();

		// Add Node To List
		nodeList.push_back (*node);

		// Delete Old Node
		delete node;

		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Calculate AStar Path
	PyObject* Python::B2D_CalculateAStar (PyObject* Self, PyObject* Args){

		// Create Variables
		int pathReference, nodeSize, startNode, endNode, mapWidth, mapHeight;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iiiiii", &pathReference, &nodeSize, &startNode, &endNode, &mapWidth, &mapHeight)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		// Set Function
		pathList[pathReference].CalculateAStar (Python::nodeList, nodeSize, startNode, endNode, mapWidth, mapHeight);

		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Calc Dijkstra's Path
	PyObject* Python::B2D_CalculateDijkstra (PyObject* Self, PyObject* Args){

		// Create Variables
		int pathReference, nodeSize, startNode, mapWidth, mapHeight; PyObject* endNode;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "iiiOii", &pathReference, &nodeSize, &startNode, &endNode, &mapWidth, &mapHeight)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		std::vector <int> endPointVector = TupleToVector (endNode);

		// Set Function
		pathList[pathReference].CalculateDijkstra (Python::nodeList, nodeSize, startNode, endPointVector, mapWidth, mapHeight, 0);

		Py_RETURN_NONE;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Follow Path
	PyObject* Python::B2D_FollowPath (PyObject* Self, PyObject* Args){

		// Create Variables
		int pathReference; float speed = 2, x, y;

		// Look For Errors
    	if (!PyArg_ParseTuple (Args, "ifff", &pathReference, &speed, &x, &y)){
    		ParsePyTupleError (__func__, __LINE__);
    	}

		Vector2::Point returnPoint (x, y);
		pathList[pathReference].FollowPath (returnPoint, speed);

		// Return Value
		return Py_BuildValue ("ff", returnPoint.x, returnPoint.y);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Convert Tuple Or List To Vector
	std::vector <int> TupleToVector (PyObject* Incoming){

		std::vector <int> data;

		// Check If Value Is A Tuple
		if (PyTuple_Check (Incoming)){

			// Get Each Element In Tuple, And Pass It Into Vector
			for (Py_ssize_t i = 0; i < PyTuple_Size (Incoming); ++i){

				PyObject* value = PyTuple_GetItem (Incoming, i);
				data.push_back ((int) PyFloat_AsDouble (value));
			}
		}

		// Check If Value Is A List
		else if (PyList_Check (Incoming)){

			// Get Each Element In List, And Pass It Into Vector
			for (Py_ssize_t i = 0; i < PyList_Size (Incoming); ++i){

				PyObject* value = PyList_GetItem (Incoming, i);
				data.push_back ((int) PyFloat_AsDouble (value));
			}
		}

		// If Neither, Throw An Error
		else{

		    std::cout << stderr << " Invalid value." << '\n';
		    return data;
		}

		// Return The Vector
		return data;
	}
}