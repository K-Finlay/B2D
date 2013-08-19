#include "Font.h"
#include "../Camera/Camera.h"
#include "../../System/System.h"
#include "../../ResourceLoading/Texture/Texture.h"
#include <iostream>
#include <GL/glew.h>

///////////////////////////////////////////
//     This File Handles Font Loading    //
//             And Rendering             //
///////////////////////////////////////////

namespace b2d{

	// Font Constructor
	Font::Font (const char* FontPath, char* Text, int Size, Vector2::Point Position, RGBA Colour, bool IsStatic, int FontType){

	    // If Pixmap Font Is Selected
		if (FontType == 0){

			// Set Font Path
			Font::pixFont = new FTGLPixmapFont (FontPath);

			// Check For Errors
			if (Font::pixFont -> Error()){

				std::cout << stderr << " The font \"" << FontPath << "\" could not be loaded" << '\n';
				return;
			}

			// Set Font Size
			Font::pixFont -> FaceSize (Size);
		}

		// If Bitmap Font Is Selected
		else if (FontType == 1){

			// Set Font Path
			Font::bitFont = new FTGLBitmapFont (FontPath);

			// Check For Errors
			if (Font::bitFont -> Error()){

				std::cout << stderr << " The font \"" << FontPath << "\" could not be loaded" << '\n';
				return;
			}

			// Set Font Size
			Font::bitFont -> FaceSize (Size);
		}

		// Else Display Error
		else{

			std::cout << stderr <<  "An invalid font type was selected. The default font type will be used" << '\n';

			// Set Font Path
			Font::pixFont = new FTGLPixmapFont (FontPath);

			// Check For Errors
			if (Font::pixFont -> Error()){

				std::cout << stderr << " The font \"" << FontPath << "\" could not be loaded" << '\n';
				return;
			}

			// Set Font Size
			Font::pixFont -> FaceSize (Size);

			FontType = 0;
		}

		// Set Font Variables
		Font::text = Text;
		Font::isStatic = IsStatic;
		Font::position = Position;
		Font::fontType = FontType;
		Font::canRender = true;
		Font::size = Size;

		Font::colour.x = Colour.colour.x;
		Font::colour.y = Colour.colour.y;
		Font::colour.z = Colour.colour.z;
		Font::colour.w = Colour.colour.w;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Render The Font
	void Font::Draw(){

		// Check If Rendering Is Enabled
		if (Font::canRender){

			// Set Text Colour
			glColor4f (Font::colour.x, Font::colour.y, Font::colour.z, Font::colour.w);

		    // If Pixmap Font Is Selected
		    if (Font::fontType == 0){

			    // Check If Font Is Static
			    if (Font::isStatic){

				    // Set Font Position
				    glRasterPos2d (b2d::Camera::position.x + Font::position.x, b2d::Camera::position.y + Font::position.y);
		        }

			    else{

				    // Set Font Position
				    glRasterPos2d (Font::position.x, Font::position.y);
			    }

			    // Render Text
			    Font::pixFont -> Render (Font::text);
		    }

		    // If Bitmap Font Is Selected
		    else if (Font::fontType == 1){

			    // Check If Font Is Static
			    if (Font::isStatic){

				    // Set Font Position
				    glRasterPos2d (b2d::Camera::position.x + Font::position.x, b2d::Camera::position.y + Font::position.y);
		        }

			    else{

				    // Set Font Position
				    glRasterPos2d (Font::position.x, Font::position.y);
			    }

				Font::bitFont -> Render (Font::text);
			}
		}
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Move Text To Absolute Position
	void Font::Move (float X, float Y){

		Font::position.SetPoint (X, Y);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Move Text To Relative Position
	void Font::Translate (float X, float Y){

		Font::position.x += (X * 50 * (float) Time::deltaTime);
		Font::position.y += (Y * 50 * (float) Time::deltaTime);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Text Colour
	void Font::SetColour (RGBA Colour){

		Font::colour.x = Colour.colour.x;
		Font::colour.y = Colour.colour.y;
		Font::colour.z = Colour.colour.z;
		Font::colour.w = Colour.colour.w;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Font Size
	void Font::SetSize (int Size){

		if (Font::fontType == 0){
			Font::pixFont -> FaceSize (Size);
		}

		else{
			Font::bitFont -> FaceSize (Size);
		}
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Font Deconstructor
	void Font::Destroy(){

		// Check Font Type And Destroy Pointers
		if (Font::fontType == 0){
		    delete Font::pixFont;
		}

		else{
		    delete Font::bitFont;
		}
	}
}