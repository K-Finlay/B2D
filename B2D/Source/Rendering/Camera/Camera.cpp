#include "Camera.h"

///////////////////////////////////////////
//     This File Controls The Camera     //
///////////////////////////////////////////

namespace b2d{

	// Init Variables
	Vector2::Point Camera::position (0, 0);
	float Camera::zoom = 1;

	// The Camera Constructor
	Camera::Camera (float PositionX, float PositionY, float Zoom){

		Camera::position.SetPoint (PositionX, PositionY);
		Camera::Zoom (Zoom);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Move The Camera To An Absolute Position
	void Camera::Move (float X, float Y){
		Camera::position.SetPoint (X, Y);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Move The Camera To A Relative Position
	void Camera::Translate (float X, float Y ){

		Camera::position.x += (X * 50 * (float) Time::deltaTime);
		Camera::position.y += (Y * 50 * (float) Time::deltaTime);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Set The Camera Zoom
	void Camera::Zoom (float ZoomValue){
		Camera::zoom += (ZoomValue * 50 * (float) Time::deltaTime);
	}
}