#ifndef COLLISION_H
#define COLLISION_H

#include <VML/Vector2/Vector2.h>

namespace b2d{

	// Collision CLass
	class Collision{
	public:

		// Functions
		static bool GetCollision (Vector2::Point StartPoint, Vector2::Point EndPoint, 
			                      Vector2::Point StartSize = Vector2::Point (1.0f, 1.0f), 
								  Vector2::Point EndSize = Vector2::Point (1.0f, 1.0f), int CollisionType = 0);

		static Vector2::Point GetCollisionPoint (Vector2::Point StartPoint, Vector2::Point EndPoint, float StartSize = 1, float EndSize = 1);

	private:

		// Functions
		static bool CircleCollision (Vector2::Point StartPoint, Vector2::Point EndPoint, float StartSize, float EndSize);
		static bool BoxCollision (Vector2::Point StartPoint, Vector2::Point EndPoint, Vector2::Point StartSize, Vector2::Point EndSize);
	};
}

#endif