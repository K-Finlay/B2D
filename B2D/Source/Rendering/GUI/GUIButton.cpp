#include "GUI.h"
#include "../../Collision/Collision.h"
#include "../../Input/Input.h"
#include <GL/glew.h>

//#ifdef __linux__
    #include <GL/gl.h>
//#endif

///////////////////////////////////////////
//     This File Handles The Creation    //
//       And Rendering Of A Button       //
///////////////////////////////////////////

namespace b2d{

	// GUI Button Constructor
	GUIButton::GUIButton (float X, float Y, int Width, int Height, char* TexNorm, char* TexOver, RGBA Colour){

		// Setup Points
		GUIButton::vertexPoints[0] = Matrix::Translate (Vector2::Point (X - Width / 2, Y - Height / 2));
		GUIButton::vertexPoints[1] = Matrix::Translate (Vector2::Point (X + Width / 2, Y - Height / 2));
		GUIButton::vertexPoints[2] = Matrix::Translate (Vector2::Point (X + Width / 2, Y + Height / 2));
		GUIButton::vertexPoints[3] = Matrix::Translate (Vector2::Point (X - Width / 2, Y + Height / 2));

		GUIButton::oldVerts[0] = GUIButton::vertexPoints[0];
		GUIButton::oldVerts[1] = GUIButton::vertexPoints[1];
		GUIButton::oldVerts[2] = GUIButton::vertexPoints[2];
		GUIButton::oldVerts[3] = GUIButton::vertexPoints[3];

		// Set Variables
		GUIButton::position = Vector2::Point (X, Y);
		GUIButton::width = (float) Width;
		GUIButton::height = (float) Height;
		GUIButton::rotation = 180;

		// Load Textures
		GLuint texID01 = 0;
		GLuint texID02 = 0;
		GUIButton::glTexNorm = Texture::LoadTexture (TexNorm, texID01);
		GUIButton::glTexOver = Texture::LoadTexture (TexOver, texID02);

		// Set Colour
		GUIButton::colour = Colour.colour;

		// Create Buffers
		glGenBuffers (1, &vboID);

		// Set More Variables
		GUIButton::canRender = true;
		GUIButton::isClicked = false;

		GUIButton::Update();
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Update VBO
	void GUIButton::Update(){

		// Set Vertices And Texture Coords
		float vertices[] = {GUIButton::vertexPoints[0].x, GUIButton::vertexPoints[0].y,
	                        GUIButton::vertexPoints[1].x, GUIButton::vertexPoints[1].y,
			                GUIButton::vertexPoints[2].x, GUIButton::vertexPoints[2].y,
			                GUIButton::vertexPoints[3].x, GUIButton::vertexPoints[3].y,
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

	// Button Renderer
	void GUIButton::Draw(){

		// Check If Rendering Is Enabled
		if (GUIButton::canRender){
			
			// Check For Vert Change
			if (GUIButton::oldVerts[0] != GUIButton::vertexPoints[0] || GUIButton::oldVerts[1] != GUIButton::vertexPoints[1], 
				GUIButton::oldVerts[2] != GUIButton::vertexPoints[2] || GUIButton::oldVerts[3] != GUIButton::vertexPoints[3]){

					// Update Verts
					Update();

					GUIButton::oldVerts[0] = GUIButton::vertexPoints[0];
		            GUIButton::oldVerts[1] = GUIButton::vertexPoints[1];
		            GUIButton::oldVerts[2] = GUIButton::vertexPoints[2];
		            GUIButton::oldVerts[3] = GUIButton::vertexPoints[3];
			}
		    
			// Check For Mouse Over
			if (Collision::GetCollision (GUIButton::position, Input::GetMousePosition(), Vector2::Point (GUIButton::width, GUIButton::height), Vector2::Point (1, 1), 1)){
				glBindTexture (GL_TEXTURE_2D, GUIButton::glTexOver);
			}

			else{
				glBindTexture (GL_TEXTURE_2D, GUIButton::glTexNorm);
			}

		    // Bind Buffers
		    glBindBuffer (GL_ARRAY_BUFFER, vboID);
		    
		    // Enable Client States
		    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		    glEnableClientState (GL_VERTEX_ARRAY);
		    
		    // Set Vertex Pointer And Tex Coord Pointer
		    glVertexPointer (2, GL_FLOAT, 8, 0);
		    glTexCoordPointer (2, GL_FLOAT, 8, (void*) 32);
		    
		    // Set Button Colour
		    glColor4f (GUIButton::colour.x, GUIButton::colour.y, GUIButton::colour.z, GUIButton::colour.w);
		    
		    // Draw Button
		    glDrawArrays (GL_TRIANGLE_FAN, 0, 4);
		    
		    // Disable Client States
		    glDisableClientState (GL_TEXTURE_COORD_ARRAY);
		    glDisableClientState (GL_VERTEX_ARRAY);
		    
		    // Unbind Texture And Vertex Buffer
		    glBindTexture (GL_TEXTURE_2D, 0);
		    glBindBuffer (GL_ARRAY_BUFFER, 0);
		}
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get Button Click
	bool GUIButton::GetClick(){

		// Check For Collision With Mouse
		if (Collision::GetCollision (GUIButton::position, Input::GetMousePosition(), Vector2::Point (GUIButton::width, GUIButton::height), Vector2::Point (1, 1), 1) && GUIButton::canRender){

			// If Button Is Not Already Clicked, Return True
			if (Input::GetMouseButton (MOUSE_LEFT) && isClicked == false){

				isClicked = true;
				return true;
			}

			// If Button Is Already Clicked, Return False
			else if (Input::GetMouseButton (MOUSE_LEFT) && isClicked == true){
				return false;
			}
		}

		// If Mouse Is Not Over Button Or Not Clicked, Return False
		isClicked = false;

		return false;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get Mouse Over Button
	bool GUIButton::GetOver(){

	    if (Collision::GetCollision (GUIButton::position, Input::GetMousePosition(), Vector2::Point (GUIButton::width, GUIButton::height), Vector2::Point (1, 1), 1) && GUIButton::canRender){
		    return true;
	    }

	    else{
		    return false;
	    }
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Swap The Current Textures
	void GUIButton::SwapTexture (char* TexNorm, char* TexOver){

		GUIButton::Destroy();
		GLuint texID01 = 0;
		GLuint texID02 = 0;
		GUIButton::glTexNorm = Texture::LoadTexture (TexNorm, texID01);
		GUIButton::glTexOver = Texture::LoadTexture (TexOver, texID02);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Reload The Button Data
	void GUIButton::Reload (float X, float Y, int Width, int Height, char* TexNorm, char* TexOver, RGBA Colour){

		GUIButton::Destroy();
        //GUIButton::GUIButton (X, Y, Width, Height, TexNorm, TexOver, Colour);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Button Destructor
	void GUIButton::Destroy(){

		// Delete Button Textures
		glDeleteTexturesEXT (1, &glTexNorm);
		glDeleteTexturesEXT (1, &glTexOver);
	}
}
