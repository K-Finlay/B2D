#include "Shaders.h"
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <string>

/////////////////////////////////////////
// This File Controls Everything To Do //
// With Shader Creation And Management //
/////////////////////////////////////////

namespace b2d{

	// Loads A Shader
	unsigned int Shader::LoadShader (char* ShaderFile, GLenum Type){

		// Setup File Loading Variables
		std::ifstream in (ShaderFile);
		std::string src = "";
		std::string line = "";

		// Setup Shader Variables
		GLuint shader;

		// Loop Through Shader And Add To String
		while (std::getline (in, line)){
			src += line + '\n';
		}

		// Create And Compile Shader
		shader = glCreateShader (Type);

		const char* source = src.c_str();

		glShaderSource (shader, 1, &source, NULL);
		glCompileShader (shader);

		// Check If Compilation Was Successful
		if (!shader){

			std::cout << stderr << " The shader \"" << ShaderFile << "\" could not be compiled" << '\n';
			return 0;
		}

		return shader;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Create A Shader Program
	GLuint Shader::CreateShaderProgram (char* VertexShader, char* FragmentShader){

		// Setup Shader Variables
		GLuint vertexShader, fragmentShader, programId;
		GLint linked;

		// Load Shaders
		vertexShader = LoadShader (VertexShader, GL_VERTEX_SHADER);
		fragmentShader = LoadShader (FragmentShader, GL_FRAGMENT_SHADER);

		programId = glCreateProgram();

		if (!vertexShader){
			return 0;
		}

		// Attach Shaders
		glAttachShader (programId, vertexShader);
		glAttachShader (programId, fragmentShader);

		// Link Shader Program
		glBindFragDataLocation (programId, 0, "color" );
		glGetProgramiv (programId, GL_LINK_STATUS, &linked);
		glLinkProgram (programId);

		// Check For Errors
		if (!linked){

			std::cout << stderr << " The shader could not be linked" << '\n';
			return 0;
		}

		glUseProgram (programId);
		return programId;
	}
}