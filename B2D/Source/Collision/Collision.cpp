#include "Collision.h"
#include <iostream>

///////////////////////////////////////////
//        This File Handles basic        //
//          collision detection          // 
///////////////////////////////////////////

namespace b2d{

	// Get Collision
	bool Collision::GetCollision (Vector2::Point StartPoint, Vector2::Point EndPoint, Vector2::Point StartSize, Vector2::Point EndSize, int CollisionType){

		bool collisionDetected;

		// Check If Circle Collision Selected
		if (CollisionType == 0){
			collisionDetected = Collision::CircleCollision (StartPoint, EndPoint, StartSize.x, EndSize.y);
		}

		// Check If Box Collision Selected
		else if (CollisionType == 1){
			collisionDetected = Collision::BoxCollision (StartPoint, EndPoint, StartSize, EndSize);
		}

		// Check If An Invalid Collision Type Has Been Selected
		else{

			std::cout << stderr << "Invalid collision type selected." << '\n';
			return false;
		}

		// Return Collision Detection
		return collisionDetected;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Get CollisionPoint
	Vector2::Point Collision::GetCollisionPoint (Vector2::Point StartPoint, Vector2::Point EndPoint, float StartSize, float EndSize){

	    // Create Collision Point Variable
		Vector2::Point CollisionPoint;

		// Calculate Collision Point
		StartSize /= 2;
		EndSize /= 2;

		CollisionPoint.SetPoint (((StartPoint.x * EndSize) + (EndPoint.x * StartSize)) / (StartSize + EndSize), ((StartPoint.y * EndSize) + (EndPoint.y * StartSize)) / (StartSize + EndSize));

		// Return Point
		return CollisionPoint;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Circle Collision Detection
	bool Collision::CircleCollision (Vector2::Point StartPoint, Vector2::Point EndPoint, float StartSize, float EndSize){

		// Get Distance Between Two Objects
		float objectDistance = Vector2::Magnitude (StartPoint, EndPoint);

		// Check For Collision
		if ((StartSize / 2 + EndSize / 2) >= objectDistance){
			return true;
		}

		else{
			return false;
		}
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Box Collision Detection
	bool Collision::BoxCollision (Vector2::Point StartPoint, Vector2::Point EndPoint, Vector2::Point StartSize, Vector2::Point EndSize){

		if ((StartPoint.x + (StartSize.x / 2)) > (EndPoint.x - (EndSize.x / 2)) && (StartPoint.x - (StartSize.x / 2)) < (EndPoint.x + (EndSize.x / 2))){

			if ((StartPoint.y + (StartSize.y / 2)) > (EndPoint.y - (EndSize.y / 2)) && (StartPoint.y - (StartSize.y / 2)) < (EndPoint.y + (EndSize.y / 2))){

				return true;
			}
		}

		return false;
	}
}