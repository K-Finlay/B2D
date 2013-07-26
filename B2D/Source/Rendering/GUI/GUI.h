#ifndef GUI_H
#define GUI_H

#include "../Primitive/Primitive.h"
#include "../../ResourceLoading/Texture/Texture.h"

namespace b2d{

	// GUI Button Class
	class GUIButton : private Square{
	public:

		// Constructors
		GUIButton();
		GUIButton (float X, float Y, int Width, int Height, char* TexNorm, char* TexOver, RGBA Colour = RGBA (1.0f, 1.0f, 1.0f, 1.0f));

		// Functions
		using Square::Move;
		using Square::Translate;
		using Square::Scale;
		void Update();
		void Draw();
		bool GetClick();
		bool GetOver();
		void SwapTexture (char* TexNorm, char* TexOver);
		void Reload (float X, float Y, int Width, int Height, char* TexNorm, char* TexOver, RGBA Colour = RGBA (1.0f, 1.0f, 1.0f, 1.0f));
		void Destroy();

		// Variables
		using Square::position;
		using Square::rotation;
		using Square::canRender;
		using Square::colour;
		bool isClicked;

	private:

		// Variables
		unsigned int glTexNorm;
		unsigned int glTexOver;
		unsigned int vboID;
		Vector2::Point oldVerts[4];
	};
}

#endif