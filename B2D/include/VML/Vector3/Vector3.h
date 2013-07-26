#ifndef VECTOR3_H
#define VECTOR3_H

#ifndef VML_EXP
#define VML_EXP __declspec (dllexport)
#endif

namespace Vector3{

	class Point{
	public:

		float x, y, z;

		VML_EXP void SetPoint (float xPoint, float yPoint, float zPoint){

			x = xPoint;
			y = yPoint;
			x = zPoint;
		}

		// Add Operator
	    VML_EXP Point operator + (const Point &vector){

			Point result;
			result.x = x + vector.x;
			result.y = y + vector.y;
			result.z = z + vector.z;

			return result;
		}

		// Add Equals Operator
		VML_EXP Point operator += (const Point &vector){

			Point result;
			result.x = x + vector.x;
			result.y = y + vector.y;
			result.z = z + vector.z;

			return result;
		}

		//Subtract Operator
		VML_EXP Point operator - (const Point &vector){

			Point result;
			result.x = x - vector.x;
			result.y = y - vector.y;
			result.z = z - vector.z;

			return result;
		}

		// Subtract Equals Operator
		VML_EXP Point operator -= (const Point &vector){

			Point result;
			result.x = x - vector.x;
			result.y = y - vector.y;
			result.z = z - vector.z;

			return result;
		}

		//Multiply Operator
		VML_EXP Point operator * (const Point &vector){

			Point result;
			result.x = x * vector.x;
			result.y = y * vector.y;
			result.z = z * vector.z;

			return result;
		}

		// Multiply Equals Operator
		VML_EXP Point operator *= (const Point &vector){

			Point result;
			result.x = x * vector.x;
			result.y = y * vector.y;
			result.z = z * vector.z;

			return result;
		}

		//Divide Operator
		VML_EXP Point operator / (const Point &vector){

			Point result;
			result.x = x / vector.x;
			result.y = y / vector.y;
			result.z = z / vector.z;

			return result;
		}

		// Divide Equals Operator
		VML_EXP Point operator /= (const Point &vector){

			Point result;
			result.x = x / vector.x;
			result.y = y / vector.y;
			result.z = z / vector.z;

			return result;
		}

		// Is Equal To Operator
		VML_EXP bool operator == (const Point &vector){

			if (x == vector.x && y == vector.y && z == vector.z){
				return true;
			}

			else{
				return false;
			}
		}

		// Not Equal To Operator
		VML_EXP bool operator != (const Point &vector){

			if (x != vector.x || y != vector.y || z != vector.z){
				return true;
			}

			else{
				return false;
			}
		}

		// Greater Then Operator
		VML_EXP bool operator > (const Point &vector){

			if ((x + y + z) > (vector.x + vector.y + vector.z)){
				return true;
			}

			else{
				return false;
			}
		}

		// Greater Then Or Equal To Operator
		VML_EXP bool operator >= (const Point &vector){

			if ((x + y + z) >= (vector.x + vector.y + vector.z)){
				return true;
			}

			else{
				return false;
			}
		}

		// Less Then Operator
		VML_EXP bool operator < (const Point &vector){

			if ((x + y + z) < (vector.x + vector.y + vector.z)){
				return true;
			}

			else{
				return false;
			}
		}

		// Less Then Or Equal To Operator
		VML_EXP bool operator <= (const Point &vector){

			if ((x + y + z) <= (vector.x + vector.y + vector.z)){
				return true;
			}

			else{
				return false;
			}
		}
	};

	VML_EXP float Magnitude (Point startPoint, Point endPoint);
	VML_EXP Point Normalize (Point startPoint, Point endPoint);
	VML_EXP float Dot (Point vectorA, Point vectorB);
	VML_EXP Point Lerp (Point vectorA, Point vectorB, float value);
	VML_EXP Point CrossProduct (Point vectorA, Point vectorB);
}

#endif