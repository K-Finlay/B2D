#include "System.h"
#include <Windows.h>

///////////////////////////////////////////
//       This File Handles All Of        //
//      The Misc. System Functions       // 
///////////////////////////////////////////

namespace b2d{

	// Get The Display Width In Pixels
	int System::GetDisplayWidth(){

		// Set Variables
		RECT screenRect;

		// Get Screen Size
		GetWindowRect (GetDesktopWindow(), &screenRect);

		// Return Window Width
		return (int) screenRect.right;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get The Display Height In Pixels
	int System::GetDisplayHeight(){

		// Set Variables
		RECT screenRect;

		// Get Screen Size
		GetWindowRect (GetDesktopWindow(), &screenRect);

		// Return Window Height
		return (int) screenRect.bottom;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get Total Number Of Pixels In Display
	int System::GetDisplayPixels(){

		// Set Variables
		RECT screenRect;

		// Get Screen Size
		GetWindowRect (GetDesktopWindow(), &screenRect);

		// Return Window Pixels
		return ((int) screenRect.right) * ((int) screenRect.bottom);
	}
}