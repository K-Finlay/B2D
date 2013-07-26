#ifndef WINDOW_H
#define WINDOW_H

#include <VML/Vector4/Vector4.h>

namespace b2d{

	// The Window Class
	class Window{
	public:

		// Window Functions
	    static void CreateGameWindow (int ScreenWidth, int ScreenHeight, char* WindowTitle, bool FullScreen, int AntiAlias = 0, bool vSync = false);
		static void Clear (RGBA Colour = RGBA ("536878FF"));
		static void Close();
		static void ToggleFullScreen (bool FullScreen);
		static void SetSize (int ScreenWidth, int ScreenHeight);
		static void SetTitle (char* Title);

		// Window Variables
		static int screenWidth, screenHeight;
		static char* windowTitle;
		static bool fullScreen;
	};

	bool GameLoop();
}

#endif