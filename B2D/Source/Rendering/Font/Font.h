#ifndef FONT_H
#define FONT_H

#include <FTGL/ftgl.h>
#include <VML/Vector2/Vector2.h>
#include <VML/Vector4/Vector4.h>

namespace b2d{

	// The Font Class
	class Font{
	public:

		// Constructors
		Font (const char* FontPath, char* Text, int Size, Vector2::Point Position, RGBA Colour = RGBA (1, 1, 1, 1), bool IsStatic = true, int FontType = 0);
		~Font();

		// Functions
		void Render();
		void Move (float X, float Y);
		void Translate (float X, float Y);
		void SetTexture (char* TexturePath);
		void SetColour (RGBA Colour);
		void SetSize (int Size);

		// Variables
		Vector2::Point position;
		Vector4::Point colour;
		char* text;
		bool isStatic;
		bool canRender;
		int size;

	private:

		// Variables
		FTGLPixmapFont* pixFont;
		FTGLBitmapFont* bitFont;
		int fontType;
	};
}

#endif