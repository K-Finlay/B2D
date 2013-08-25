#include "System.h"
#include <GL/glfw.h>

///////////////////////////////////////////
//       This File Handles All Of        //
//      The Misc. System Functions       //
///////////////////////////////////////////

namespace b2d{

	// Get The Display Width In Pixels
	int System::GetDisplayWidth(){

		// Set Variables
		GLFWvidmode return_struct;

		// Get Screen Size
		glfwGetDesktopMode (&return_struct);

		// Return Window Width
		return (int) return_struct.Width;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get The Display Height In Pixels
	int System::GetDisplayHeight(){

		// Set Variables
		GLFWvidmode return_struct;

		// Get Screen Size
		glfwGetDesktopMode (&return_struct);

		// Return Window Height
		return (int) return_struct.Height;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get Total Number Of Pixels In Display
	int System::GetDisplayPixels(){

		// Set Variables
		GLFWvidmode return_struct;

		// Get Screen Size
		glfwGetDesktopMode (&return_struct);

		// Return Window Pixels
		return ((int) return_struct.Width) * ((int) return_struct.Height);
	}
}
