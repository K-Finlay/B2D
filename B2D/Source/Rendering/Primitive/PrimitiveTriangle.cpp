#include "Primitive.h"
#include <GL/glew.h>

///////////////////////////////////////////
//     This File Handles The Creation    //
// And Rendering Of A Primitive Triangle //
///////////////////////////////////////////

namespace b2d{

	// Triangle Primitive Constructor
	Triangle::Triangle (Vector2::Point Point01, Vector2::Point Point02, Vector2::Point Point03, RGBA Colour){

		// Setup Points
		Triangle::vertexPoints[0] = Point01;
		Triangle::vertexPoints[1] = Point02;
		Triangle::vertexPoints[2] = Point03;

		// Set Colour
		Triangle::colour = Colour.colour;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Triangle Renderer
	void Triangle::Draw(){

		// Create Vert Array
		int vertices[] = {(int) Triangle::vertexPoints[0].x, (int) Triangle::vertexPoints[0].y,
                          (int) Triangle::vertexPoints[1].x, (int) Triangle::vertexPoints[1].y,
						  (int) Triangle::vertexPoints[2].x, (int) Triangle::vertexPoints[2].y};

		// Enable Client States
		glEnableClientState (GL_VERTEX_ARRAY);

		// Set Vertex Pointer
		glVertexPointer (2, GL_INT, 0, vertices);

		// Set Triangle Colour
		glColor4f (Triangle::colour.x, Triangle::colour.y, Triangle::colour.z, Triangle::colour.w);

		// Draw Triangle
		glDrawArrays (GL_TRIANGLE_STRIP, 0, 3);

		// Disable Client States
		glDisableClientState (GL_VERTEX_ARRAY);
	}
}