#ifndef VECTOR2_H
#define VECTOR2_H

#ifndef VML_EXP
#define VML_EXP __declspec (dllexport)
#endif

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

		VML_EXP void SetPoint (float xPoint, float yPoint){

			x = xPoint;
			y = yPoint;
		}

		// Add Operator
	    VML_EXP Point operator + (const Point &vector){

			Point result;
			result.x = x + vector.x;
			result.y = y + vector.y;

			return result;
		}

		// Add Equals Operator
		VML_EXP Point operator += (const Point &vector){

			Point result;
			result.x = x + vector.x;
			result.y = y + vector.y;

			return result;
		}

		//Subtract Operator
		VML_EXP Point operator - (const Point &vector){

			Point result;
			result.x = x - vector.x;
			result.y = y - vector.y;

			return result;
		}

		// Subtract Equals Operator
		VML_EXP Point operator -= (const Point &vector){

			Point result;
			result.x = x - vector.x;
			result.y = y - vector.y;

			return result;
		}

		//Multiply Operator
		VML_EXP Point operator * (const Point &vector){

			Point result;
			result.x = x * vector.x;
			result.y = y * vector.y;

			return result;
		}

		// Multiply Equals Operator
		VML_EXP Point operator *= (const Point &vector){

			Point result;
			result.x = x * vector.x;
			result.y = y * vector.y;

			return result;
		}

		//Divide Operator
		VML_EXP Point operator / (const Point &vector){

			Point result;
			result.x = x / vector.x;
			result.y = y / vector.y;

			return result;
		}

		// Divide Equals Operator
		VML_EXP Point operator /= (const Point &vector){

			Point result;
			result.x = x / vector.x;
			result.y = y / vector.y;

			return result;
		}

		// Is Equal To Operator
		VML_EXP bool operator == (const Point &vector){

			if (x == vector.x && y == vector.y){
				return true;
			}

			else{
				return false;
			}
		}

		// Not Equal To Operator
		VML_EXP bool operator != (const Point &vector){

			if (x != vector.x || y != vector.y){
				return true;
			}

			else{
				return false;
			}
		}

		// Greater Then Operator
		VML_EXP bool operator > (const Point &vector){

			if ((x + y) > (vector.x + vector.y)){
				return true;
			}

			else{
				return false;
			}
		}

		// Greater Then Or Equal To Operator
		VML_EXP bool operator >= (const Point &vector){

			if ((x + y) >= (vector.x + vector.y)){
				return true;
			}

			else{
				return false;
			}
		}

		// Less Then Operator
		VML_EXP bool operator < (const Point &vector){

			if ((x + y) < (vector.x + vector.y)){
				return true;
			}

			else{
				return false;
			}
		}

		// Less Then Or Equal To Operator
		VML_EXP bool operator <= (const Point &vector){

			if ((x + y) <= (vector.x + vector.y)){
				return true;
			}

			else{
				return false;
			}
		}
	};

	// Vector2 Math Functions
	VML_EXP float Magnitude (Point startPoint, Point endPoint);
	VML_EXP float Magnitude (float startX, float startY, float endX, float endY); // Overloaded function for assignment 3. Remove later.

	VML_EXP float RotToPoint (Point startPoint, Point endPoint);
	VML_EXP float RotToPoint (float startX, float startY, float endX, float endY); // Overloaded function for assignment 3. Remove later.

	VML_EXP Point Normalize (Point startPoint, Point endPoint);
	VML_EXP float Dot (Point vectorA, Point vectorB);
	VML_EXP Point Lerp (Point vectorA, Point vectorB, float value);
}

#endif