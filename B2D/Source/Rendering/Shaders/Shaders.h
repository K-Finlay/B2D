#ifndef SHADERS_H
#define SHADERS_H

namespace b2d{

	class Shader{
	public:

		static unsigned int LoadShader (char* ShaderFile, unsigned int Type);
		static unsigned int CreateShaderProgram (char* VertexShader, char* FragmentShader);
	};
}

#endif