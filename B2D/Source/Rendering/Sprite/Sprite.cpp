#include "Sprite.h"
#include <GL/glew.h>

///////////////////////////////////////////
//     This File Handles The Creation    //
//       And Rendering Of A Sprite       //
///////////////////////////////////////////

namespace b2d{

	// Sprite Constructor
	Sprite::Sprite (Vector2::Point Position, int Width, int Height, char* TexturePath, RGBA Colour){

		// Setup Points
		Sprite::vertexPoints[0] = Matrix::Translate (Vector2::Point (Position.x - Width / 2, Position.y - Height / 2));
		Sprite::vertexPoints[1] = Matrix::Translate (Vector2::Point (Position.x + Width / 2, Position.y - Height / 2));
		Sprite::vertexPoints[2] = Matrix::Translate (Vector2::Point (Position.x + Width / 2, Position.y + Height / 2));
		Sprite::vertexPoints[3] = Matrix::Translate (Vector2::Point (Position.x - Width / 2, Position.y + Height / 2));

		Sprite::oldVerts[0] = Sprite::vertexPoints[0];
		Sprite::oldVerts[1] = Sprite::vertexPoints[1];
		Sprite::oldVerts[2] = Sprite::vertexPoints[2];
		Sprite::oldVerts[3] = Sprite::vertexPoints[3];

		// Set Variables
		Sprite::position = Position;
		Sprite::width = (float) Width;
		Sprite::height = (float) Height;
		Sprite::rotation = 180;

		Sprite::isAnimated = false;
		Sprite::endNum = 0;
		Sprite::currentFrame = 0;
		Sprite::frameSize = 1;
		Sprite::animationSpeed = 0;
		Sprite::animationWaitTime = 0;
		Sprite::isStatic = false;

		// Load Texture
		GLuint texID = 0;
		Sprite::glTex = Texture::LoadTexture (TexturePath, texID);

		// Set Colour
		Sprite::colour = Colour.colour;

		// Turn On Rendering
		Sprite::canRender = true;

		// Create Buffers
		glGenBuffers (1, &vboID);

		// Update Verts
		Sprite::Update();
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Swap The Current Texture For Another One
	void Sprite::SwapTexture (char* TexturePath){

		Sprite::Destroy();
		GLuint texID = 0;
		Sprite::glTex = Texture::LoadTexture (TexturePath, texID);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set Up Animation
	void Sprite::PlayAnimation (int NumOfFrames, int StartNum, int EndNum, float AnimationSpeed){

		Sprite::startNum = StartNum;
		Sprite::endNum = EndNum;
		Sprite::currentFrame = StartNum;
		Sprite::frameSize = 1.0 / NumOfFrames;
		Sprite::animationSpeed = AnimationSpeed;
		Sprite::isAnimated = true;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Animation To The Specified Frame
	void Sprite::SetFrame (int NumOfFrames, int Frame){

		Sprite::frameSize = 1.0 / NumOfFrames;
		Sprite::currentFrame = Frame;

		Sprite::Update();
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Stop The Animation
	void Sprite::StopAnimation(){
		Sprite::isAnimated = false;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Resume The Current Animation
	void Sprite::ResumeAnimation(){
		Sprite::isAnimated = true;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Update VBO
	void Sprite::Update(){

		// Set Vertices
		float vertices[] = {Sprite::vertexPoints[0].x, Sprite::vertexPoints[0].y,
	                        Sprite::vertexPoints[1].x, Sprite::vertexPoints[1].y,
			                Sprite::vertexPoints[2].x, Sprite::vertexPoints[2].y,
			                Sprite::vertexPoints[3].x, Sprite::vertexPoints[3].y,
		                    (float) frameSize * currentFrame, 1,
		                    (float) frameSize * (currentFrame + 1), 1,
		                    (float) frameSize * (currentFrame + 1), 0,
		                    (float) frameSize * currentFrame, 0};

		// Bind And Buffer VBO
		glBindBuffer (GL_ARRAY_BUFFER, vboID);
		glBufferData (GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);

		// Unbind Buffer
		glBindBuffer (GL_ARRAY_BUFFER, 0);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Sprite Renderer
	void Sprite::Draw(){

		// Check If Rendering Is Enabled
		if (Sprite::canRender){

			// Check For Animation
			if (Sprite::isAnimated){

				// Increment Wait Time
				Sprite::animationWaitTime += Time::deltaTime;

				// If Wait Time Is Equal To Animation Speed
				if (Sprite::animationWaitTime >= Sprite::animationSpeed){

					// Move To Next Animation Frame
					Sprite::currentFrame += 1;

					// Check For End Frame
					if (Sprite::currentFrame == Sprite::endNum){
						Sprite::currentFrame = Sprite::startNum;
					}

					// Set The Wait Time To 0
					Sprite::animationWaitTime = 0;

					// Update UV Coordinates
					Update();
				}
			}
			
			// Check For Vert Change
			if (Sprite::oldVerts[0] != Sprite::vertexPoints[0] || Sprite::oldVerts[1] != Sprite::vertexPoints[1], 
				Sprite::oldVerts[2] != Sprite::vertexPoints[2] || Sprite::oldVerts[3] != Sprite::vertexPoints[3]){

					// Update Verts
					Update();

					Sprite::oldVerts[0] = Sprite::vertexPoints[0];
		            Sprite::oldVerts[1] = Sprite::vertexPoints[1];
		            Sprite::oldVerts[2] = Sprite::vertexPoints[2];
		            Sprite::oldVerts[3] = Sprite::vertexPoints[3];
			}
		    
		    // Set Texture And Bind Buffers
		    glBindTexture (GL_TEXTURE_2D, Sprite::glTex);
		    glBindBuffer (GL_ARRAY_BUFFER, vboID);
		    
		    // Enable Client States
		    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		    glEnableClientState (GL_VERTEX_ARRAY);
		    
		    // Set Vertex Pointer And Tex Coord Pointer
		    glVertexPointer (2, GL_FLOAT, 8, 0);
		    glTexCoordPointer (2, GL_FLOAT, 8, (void*) 32);
		    
		    // Set Sprite Colour
		    glColor4f (Sprite::colour.x, Sprite::colour.y, Sprite::colour.z, Sprite::colour.w);
		    
		    // Draw Sprite
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

	// Reload The Sprite Data
	void Sprite::Reload (Vector2::Point Position, int Width, int Height, char* TexturePath, RGBA Colour){

		Sprite::Destroy();
		Sprite::Sprite (Position, Width, Height, TexturePath, Colour);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Sprite Destructor
	void Sprite::Destroy(){
		glDeleteTexturesEXT (1, &glTex);
	}
}