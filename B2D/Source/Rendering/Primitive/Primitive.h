#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <VML/Vector2/Vector2.h>
#include <VML/Vector4/Vector4.h>
#include <VML/Matrix/Matrix.h>
#include <VML/Math/Math.h>
#include "../../System/System.h"

namespace b2d{

	// Triangle Primitive Class
	class Triangle{
	public:

		// Constructors
		Triangle();
		Triangle (Vector2::Point Point01, Vector2::Point Point02, Vector2::Point Point03, RGBA Colour);

		// Functions
		void Draw();

		// Variables
		Vector2::Point vertexPoints[3];
		Vector4::Point colour;

	private:

		// Variables
		unsigned int Shader;
		unsigned int vertexBuffer;
	};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Square Primitive Class
	class Square{
	public:

		// Constructors
		Square(){};
		Square (Vector2::Point Position, int Width, int Height, RGBA Colour = RGBA (1.0f, 1.0f, 1.0f, 1.0f));

		// Functions
		void Update();
		void Draw();
		void Move (float X, float Y, double Rotation);
		void Translate (float X, float Y, double Rotation);
		void Scale (float X, float Y);

		// Variables
		Vector2::Point position;
		Vector2::Point vertexPoints[4];
		Vector4::Point colour;
		float width, height;
		double rotation;
		bool canRender;
		bool isStatic;

	private:

		unsigned int vboID;
	    Vector2::Point oldVerts[4];
	};
}

#endif