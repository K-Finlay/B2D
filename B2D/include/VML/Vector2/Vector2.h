#ifndef VECTOR2_H
#define VECTOR2_H

namespace Vector2{

	class Point{
	public:

		float x, y;

		Point(){

			Point::x = 0;
			Point::y = 0;
		}

		Point (float X, float Y){

			Point::x = X;
		    Point::y = Y;
		}

         void SetPoint (float xPoint, float yPoint){

			x = xPoint;
			y = yPoint;
		}

		// Add Operator
         Point operator + (const Point &vector){

			Point result;
			result.x = x + vector.x;
			result.y = y + vector.y;

			return result;
		}

		// Add Equals Operator
         Point operator += (const Point &vector){

			Point result;
			result.x = x + vector.x;
			result.y = y + vector.y;

			return result;
		}

		//Subtract Operator
         Point operator - (const Point &vector){

			Point result;
			result.x = x - vector.x;
			result.y = y - vector.y;

			return result;
		}

		// Subtract Equals Operator
         Point operator -= (const Point &vector){

			Point result;
			result.x = x - vector.x;
			result.y = y - vector.y;

			return result;
		}

		//Multiply Operator
         Point operator * (const Point &vector){

			Point result;
			result.x = x * vector.x;
			result.y = y * vector.y;

			return result;
		}

		// Multiply Equals Operator
         Point operator *= (const Point &vector){

			Point result;
			result.x = x * vector.x;
			result.y = y * vector.y;

			return result;
		}

		//Divide Operator
         Point operator / (const Point &vector){

			Point result;
			result.x = x / vector.x;
			result.y = y / vector.y;

			return result;
		}

		// Divide Equals Operator
         Point operator /= (const Point &vector){

			Point result;
			result.x = x / vector.x;
			result.y = y / vector.y;

			return result;
		}

		// Is Equal To Operator
         bool operator == (const Point &vector){

			if (x == vector.x && y == vector.y){
				return true;
			}

			else{
				return false;
			}
		}

		// Not Equal To Operator
         bool operator != (const Point &vector){

			if (x != vector.x || y != vector.y){
				return true;
			}

			else{
				return false;
			}
		}

		// Greater Then Operator
         bool operator > (const Point &vector){

			if ((x + y) > (vector.x + vector.y)){
				return true;
			}

			else{
				return false;
			}
		}

		// Greater Then Or Equal To Operator
         bool operator >= (const Point &vector){

			if ((x + y) >= (vector.x + vector.y)){
				return true;
			}

			else{
				return false;
			}
		}

		// Less Then Operator
         bool operator < (const Point &vector){

			if ((x + y) < (vector.x + vector.y)){
				return true;
			}

			else{
				return false;
			}
		}

		// Less Then Or Equal To Operator
         bool operator <= (const Point &vector){

			if ((x + y) <= (vector.x + vector.y)){
				return true;
			}

			else{
				return false;
			}
		}
	};

	// Vector2 Math Functions
     float Magnitude (Point startPoint, Point endPoint);
     float Magnitude (float startX, float startY, float endX, float endY); // Overloaded function for assignment 3. Remove later.

     float RotToPoint (Point startPoint, Point endPoint);
     float RotToPoint (float startX, float startY, float endX, float endY); // Overloaded function for assignment 3. Remove later.

     Point Normalize (Point startPoint, Point endPoint);
     float Dot (Point vectorA, Point vectorB);
     Point Lerp (Point vectorA, Point vectorB, float value);
}

#endif
