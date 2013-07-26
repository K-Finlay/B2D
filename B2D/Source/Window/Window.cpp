#include <GL/glew.h>
#include <GL/wglew.h>
#include <Windows.h>
#include <GL/glfw.h>
#include "Window.h"
#include "../System/System.h"
#include "../Rendering/Camera/Camera.h"

/////////////////////////////////////////
// This File Controls Everything To Do //
// With Window Creation And Management //
/////////////////////////////////////////

int windowMode;

// Window Variables
int b2d::Window::screenWidth;
int b2d::Window::screenHeight;
bool b2d::Window::fullScreen;
char* b2d::Window::windowTitle;

namespace b2d{

	// Create Game Window And Init Framework
    void Window::CreateGameWindow (int ScreenWidth, int ScreenHeight, char* WindowTitle, bool FullScreen, int AntiAlias, bool vSync){

		// Check If GLFW Is Working
		if (!glfwInit()){

			MessageBox (NULL, TEXT ("GLFW could not be initialized."), TEXT ("GLFW ERROR"), MB_ICONERROR);
			return;
		}

		// Set To FullScreen If requested
		if (FullScreen == true){
			windowMode = GLFW_FULLSCREEN;
		}

		else{
			windowMode = GLFW_WINDOW;
		}

		// Check If Window Was Created
		if (!glfwOpenWindow (ScreenWidth, ScreenHeight, 8, 8, 8, 0, 24, 0, windowMode)){

			MessageBox (NULL, TEXT ("GLFW window could not be created"), TEXT ("GLFW ERROR"), MB_ICONERROR);
			return;
		}

		// Check If GLEW Is Working
		if (glewInit() != GLEW_OK){

			MessageBox (NULL, TEXT ("GLEW could not be initialized."), TEXT ("GLEW ERROR"), MB_ICONERROR);
			return;
		}

		// Set Window Title
		glfwSetWindowTitle (WindowTitle);

		// Setup OpenGL
		glEnable (GL_TEXTURE_2D);
        glEnable (GL_ALPHA_TEST);
		glEnable (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable (GL_DEPTH);
        glDepthFunc (GL_LEQUAL);

		// Set Anti-Alias Samples
		glfwOpenWindowHint (GLFW_FSAA_SAMPLES, AntiAlias);

		// Set VSync
		if (vSync == true){
			glfwSwapInterval (1);
		}

		// Store Window Variables So They Can Be Accessed Later On
		Window::screenWidth = ScreenWidth;
		Window::screenHeight = ScreenHeight;
		Window::fullScreen = FullScreen;
		Window::windowTitle = WindowTitle;
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Clear The Window
	void Window::Clear (RGBA Colour){

		// Clear Window
		glfwSwapBuffers();
	    glLoadIdentity();
        glClearDepth (1.0);
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor (Colour.colour.x, Colour.colour.y, Colour.colour.z, Colour.colour.w);
		glOrtho ((-Window::screenWidth * Camera::zoom) + Camera::position.x, (Window::screenWidth * Camera::zoom) + Camera::position.x, 
			    (Window::screenHeight * Camera::zoom) + Camera::position.y, (-Window::screenHeight * Camera::zoom) + Camera::position.y, 0.0, 100);
		glFlush();

		// Get Delta Time
		Time::GetDeltaTime();
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Close The Window
	void Window::Close(){

		glfwCloseWindow();
		glfwTerminate();
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Toggle Fullscreen Mode
	void Window::ToggleFullScreen (bool FullScreen){

		glfwCloseWindow();
		Window::CreateGameWindow (Window::screenWidth, Window::screenHeight, Window::windowTitle, FullScreen);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set Window Size
	void Window::SetSize (int ScreenWidth, int ScreenHeight){

		glfwCloseWindow();
		Window::CreateGameWindow (ScreenWidth, ScreenHeight, Window::windowTitle, Window::fullScreen);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set Window Title
	void Window::SetTitle (char* Title){

		glfwSetWindowTitle (Title);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Check For Game Loop
	bool GameLoop(){

		// Exit Loop If Window Is Closed
		if (!glfwGetWindowParam (GLFW_OPENED)){
			return false;
		}

		else{
			return true;
		}
	}
}