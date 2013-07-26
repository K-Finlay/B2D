#ifndef CAMERA_H
#define CAMERA_H

#include <VML/Vector2/Vector2.h>
#include "../../System/System.h"

namespace b2d{

	// The Camera Class
	class Camera{
	public:

		// Constructors
		Camera (float PositionX = 0, float PositionY = 0, float Zoom = 1);

		// Functions
		static void Move (float X, float Y);
		static void Translate (float X, float Y);
		static void Zoom (float ZoomValue);

		// Variables
		static Vector2::Point position;
		static float zoom;
	};
}

#endif