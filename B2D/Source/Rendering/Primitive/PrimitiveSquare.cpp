#include "Primitive.h"
#include <GL/glew.h>

///////////////////////////////////////////
//     This File Handles The Creation    //
//  And Rendering Of A Primitive Square  //
///////////////////////////////////////////

namespace b2d{

	// Square Primitive Constructor
	Square::Square (Vector2::Point Position, int Width, int Height, RGBA Colour){

		// Setup Points
		Square::vertexPoints[0] = Matrix::Translate (Vector2::Point (Position.x - Width / 2, Position.y - Height / 2));
		Square::vertexPoints[1] = Matrix::Translate (Vector2::Point (Position.x + Width / 2, Position.y - Height / 2));
		Square::vertexPoints[2] = Matrix::Translate (Vector2::Point (Position.x + Width / 2, Position.y + Height / 2));
		Square::vertexPoints[3] = Matrix::Translate (Vector2::Point (Position.x - Width / 2, Position.y + Height / 2));

		Square::oldVerts[0] = Square::vertexPoints[0];
		Square::oldVerts[1] = Square::vertexPoints[1];
		Square::oldVerts[2] = Square::vertexPoints[2];
		Square::oldVerts[3] = Square::vertexPoints[3];

		// Set Variables
		Square::position = Position;
		Square::width = (float) Width;
		Square::height = (float) Height;
		Square::rotation = 180;
		Square::isStatic = false;

		// Set Colour
		Square::colour = Colour.colour;

		// Create Buffers
		glGenBuffers (1, &vboID);
		
		// Turn On Rendering
		Square::canRender = true;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Update Square VBO
	void Square::Update(){

		// Set Vertices
		float vertices[] = {Square::vertexPoints[0].x, Square::vertexPoints[0].y,
	                        Square::vertexPoints[1].x, Square::vertexPoints[1].y,
			                Square::vertexPoints[2].x, Square::vertexPoints[2].y,
			                Square::vertexPoints[3].x, Square::vertexPoints[3].y,
		                    0, 1,
		                    1, 1,
		                    1, 0,
		                    0, 0};

		// Bind And Buffer VBO
		glBindBuffer (GL_ARRAY_BUFFER, vboID);
		glBufferData (GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);

		// Unbind Buffer
		glBindBuffer (GL_ARRAY_BUFFER, 0);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Square Renderer
	void Square::Draw(){

		// Check If Rendering Is Enabled
		if (Square::canRender){

			// Check For Vert Change
			if (Square::oldVerts[0] != Square::vertexPoints[0] || Square::oldVerts[1] != Square::vertexPoints[1], 
				Square::oldVerts[2] != Square::vertexPoints[2] || Square::oldVerts[3] != Square::vertexPoints[3]){

					// Update Verts
					Update();

					Square::oldVerts[0] = Square::vertexPoints[0];
		            Square::oldVerts[1] = Square::vertexPoints[1];
		            Square::oldVerts[2] = Square::vertexPoints[2];
		            Square::oldVerts[3] = Square::vertexPoints[3];
			}

			// Bind Buffer
			glBindBuffer (GL_ARRAY_BUFFER, vboID);

		    // Enable Client States
		    glEnableClientState (GL_VERTEX_ARRAY);

			// Set Vertex Pointer
			glVertexPointer (2, GL_FLOAT, 0, 0);
		    
		    // Set Square Colour
		    glColor4f (Square::colour.x, Square::colour.y, Square::colour.z, Square::colour.w);
		    
		    // Draw Square
		    glDrawArrays (GL_TRIANGLE_FAN, 0, 4);
		    
		    // Disable Client States
		    glDisableClientState (GL_VERTEX_ARRAY);

			// Unbind Texture And Vertex Buffer
		    glBindBuffer (GL_ARRAY_BUFFER, 0);
		}
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Move Square To Absolute Position
	void Square::Move (float X, float Y, double Rotation){

		if (!Square::isStatic){

		    // Set Square Rotation Variable
		    Square::rotation = Rotation;
		    Vector2::Point rotatedPoint;
		    
		    // Move Square To Origin
		    Square::vertexPoints[0] = Matrix::Translate (Vector2::Point (0 - Square::width / 2, 0 - Square::height / 2));
		    Square::vertexPoints[1] = Matrix::Translate (Vector2::Point (0 + Square::width / 2, 0 - Square::height / 2));
		    Square::vertexPoints[2] = Matrix::Translate (Vector2::Point (0 + Square::width / 2, 0 + Square::height / 2));
		    Square::vertexPoints[3] = Matrix::Translate (Vector2::Point (0 - Square::width / 2, 0 + Square::height / 2));
		    
		    // Set Square Position Variable
		    Square::position.x = X;
		    Square::position.y = Y;
		    
		    // Perform Square Rotation And Set Back To Original Position
		    rotatedPoint = Matrix::Rotate (Square::rotation, Square::vertexPoints[0]);
		    Square::vertexPoints[0] = Matrix::Translate (Vector2::Point (Square::position.x - rotatedPoint.x, Square::position.y - rotatedPoint.y));
		    
		    rotatedPoint = Matrix::Rotate (Square::rotation, Square::vertexPoints[1]);
		    Square::vertexPoints[1] = Matrix::Translate (Vector2::Point (Square::position.x - rotatedPoint.x, Square::position.y - rotatedPoint.y));
		    
		    rotatedPoint = Matrix::Rotate (Square::rotation, Square::vertexPoints[2]);
		    Square::vertexPoints[2] = Matrix::Translate (Vector2::Point (Square::position.x - rotatedPoint.x, Square::position.y - rotatedPoint.y));
		    
		    rotatedPoint = Matrix::Rotate (Square::rotation, Square::vertexPoints[3]);
		    Square::vertexPoints[3] = Matrix::Translate (Vector2::Point (Square::position.x - rotatedPoint.x, Square::position.y - rotatedPoint.y));
		}
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Move Square To Relative Position
	void Square::Translate (float X, float Y, double Rotation){

		if (!Square::isStatic){

		    // Set Square Rotation Variable
		    Square::rotation += (Rotation * 50 * Time::deltaTime);
		    Vector2::Point rotatedPoint;
		    
		    // Move Square To Origin
		    Square::vertexPoints[0] = Matrix::Translate (Vector2::Point (0 - Square::width / 2, 0 - Square::height / 2));
		    Square::vertexPoints[1] = Matrix::Translate (Vector2::Point (0 + Square::width / 2, 0 - Square::height / 2));
		    Square::vertexPoints[2] = Matrix::Translate (Vector2::Point (0 + Square::width / 2, 0 + Square::height / 2));
		    Square::vertexPoints[3] = Matrix::Translate (Vector2::Point (0 - Square::width / 2, 0 + Square::height / 2));
		    
		    // Set Square Position Variable
		    Square::position.x += (X * 50 * (float) Time::deltaTime);
		    Square::position.y += (Y * 50 * (float) Time::deltaTime);
		    
		    // Perform Square Rotation And Set Back To Original Position
		    rotatedPoint = Matrix::Rotate (Square::rotation, Square::vertexPoints[0]);
		    Square::vertexPoints[0] = Matrix::Translate (Vector2::Point (Square::position.x - rotatedPoint.x, Square::position.y - rotatedPoint.y));
		    
		    rotatedPoint = Matrix::Rotate (Square::rotation, Square::vertexPoints[1]);
		    Square::vertexPoints[1] = Matrix::Translate (Vector2::Point (Square::position.x - rotatedPoint.x, Square::position.y - rotatedPoint.y));
		    
		    rotatedPoint = Matrix::Rotate (Square::rotation, Square::vertexPoints[2]);
		    Square::vertexPoints[2] = Matrix::Translate (Vector2::Point (Square::position.x - rotatedPoint.x, Square::position.y - rotatedPoint.y));
		    
		    rotatedPoint = Matrix::Rotate (Square::rotation, Square::vertexPoints[3]);
		    Square::vertexPoints[3] = Matrix::Translate (Vector2::Point (Square::position.x - rotatedPoint.x, Square::position.y - rotatedPoint.y));
		}
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Scale The Square
	void Square::Scale (float X, float Y){

		if (!Square::isStatic){

		    // Take Delta Time Into Account
		    float scaleX = (X * 50 * (float) Time::deltaTime);
		    float scaleY = (Y * 50 * (float) Time::deltaTime);
		    
		    // Set Square Width And Height Variable
		    Square::width += scaleX;
		    Square::height += scaleY;
		    
		    // Scale The Square Vertices
		    Square::vertexPoints[0] = Matrix::Scale (Vector2::Point (-scaleX, -scaleY), Square::vertexPoints[0]);
		    Square::vertexPoints[1] = Matrix::Scale (Vector2::Point (scaleX, -scaleY), Square::vertexPoints[1]);
		    Square::vertexPoints[2] = Matrix::Scale (Vector2::Point (scaleX, scaleY), Square::vertexPoints[2]);
		    Square::vertexPoints[3] = Matrix::Scale (Vector2::Point (-scaleX, scaleY), Square::vertexPoints[3]);
		    
		    // Move Back To Original Position
		    Square::Move (Square::position.x, Square::position.y, Square::rotation);
		}
	}
}