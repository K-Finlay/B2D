#include <GL/glfw.h>
#include "Input.h"
#include "../Window/Window.h"

///////////////////////////////////////////
//     This File Handles User Input      //
///////////////////////////////////////////

namespace b2d{

	// Get Keyboard Input
	bool Input::GetKey (b2d::Key Key){

		if (glfwGetKey (Key)){
			return true;
		}

		else{
			return false;
		}
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get Mouse Button Input
	bool Input::GetMouseButton (b2d::Mouse Mouse){

		if (glfwGetMouseButton (Mouse)){
			return true;
		}

		else{
			return false;
		}
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get Mouse Position
	Vector2::Point Input::GetMousePosition(){

		int MouseX, MouseY;
		glfwGetMousePos (&MouseX, &MouseY);

		return (Vector2::Point ((float) ((-Window::screenWidth + MouseX * 2) * Camera::zoom) + Camera::position.x, 
			                   (float) ((-Window::screenHeight + MouseY * 2) * Camera::zoom) + Camera::position.y));
	}
}