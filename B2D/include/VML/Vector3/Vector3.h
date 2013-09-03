#ifndef VECTOR3_H
#define VECTOR3_H

namespace Vector3{

	class Point{
	public:

		float x, y, z;

         void SetPoint (float xPoint, float yPoint, float zPoint){

			x = xPoint;
			y = yPoint;
			x = zPoint;
		}

		// Add Operator
         Point operator + (const Point &vector){

			Point result;
			result.x = x + vector.x;
			result.y = y + vector.y;
			result.z = z + vector.z;

			return result;
		}

		// Add Equals Operator
         Point operator += (const Point &vector){

			Point result;
			result.x = x + vector.x;
			result.y = y + vector.y;
			result.z = z + vector.z;

			return result;
		}

		//Subtract Operator
         Point operator - (const Point &vector){

			Point result;
			result.x = x - vector.x;
			result.y = y - vector.y;
			result.z = z - vector.z;

			return result;
		}

		// Subtract Equals Operator
         Point operator -= (const Point &vector){

			Point result;
			result.x = x - vector.x;
			result.y = y - vector.y;
			result.z = z - vector.z;

			return result;
		}

		//Multiply Operator
         Point operator * (const Point &vector){

			Point result;
			result.x = x * vector.x;
			result.y = y * vector.y;
			result.z = z * vector.z;

			return result;
		}

		// Multiply Equals Operator
         Point operator *= (const Point &vector){

			Point result;
			result.x = x * vector.x;
			result.y = y * vector.y;
			result.z = z * vector.z;

			return result;
		}

		//Divide Operator
         Point operator / (const Point &vector){

			Point result;
			result.x = x / vector.x;
			result.y = y / vector.y;
			result.z = z / vector.z;

			return result;
		}

		// Divide Equals Operator
         Point operator /= (const Point &vector){

			Point result;
			result.x = x / vector.x;
			result.y = y / vector.y;
			result.z = z / vector.z;

			return result;
		}

		// Is Equal To Operator
         bool operator == (const Point &vector){

			if (x == vector.x && y == vector.y && z == vector.z){
				return true;
			}

			else{
				return false;
			}
		}

		// Not Equal To Operator
         bool operator != (const Point &vector){

			if (x != vector.x || y != vector.y || z != vector.z){
				return true;
			}

			else{
				return false;
			}
		}

		// Greater Then Operator
         bool operator > (const Point &vector){

			if ((x + y + z) > (vector.x + vector.y + vector.z)){
				return true;
			}

			else{
				return false;
			}
		}

		// Greater Then Or Equal To Operator
         bool operator >= (const Point &vector){

			if ((x + y + z) >= (vector.x + vector.y + vector.z)){
				return true;
			}

			else{
				return false;
			}
		}

		// Less Then Operator
         bool operator < (const Point &vector){

			if ((x + y + z) < (vector.x + vector.y + vector.z)){
				return true;
			}

			else{
				return false;
			}
		}

		// Less Then Or Equal To Operator
         bool operator <= (const Point &vector){

			if ((x + y + z) <= (vector.x + vector.y + vector.z)){
				return true;
			}

			else{
				return false;
			}
		}
	};

     float Magnitude (Point startPoint, Point endPoint);
     Point Normalize (Point startPoint, Point endPoint);
     float Dot (Point vectorA, Point vectorB);
     Point Lerp (Point vectorA, Point vectorB, float value);
     Point CrossProduct (Point vectorA, Point vectorB);
}

#endif
