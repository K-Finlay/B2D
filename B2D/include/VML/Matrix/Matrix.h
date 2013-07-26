#ifndef MATRIX_H
#define MATRIX_H

#ifndef VML_EXP
#define VML_EXP __declspec (dllexport)
#endif

#include "../Vector2/Vector2.h"
#include "../Vector3/Vector3.h"
#include "../Math/Math.h"

namespace Matrix{

	// 3x3 Matrix
	class X3{
	public:

		VML_EXP X3();
		VML_EXP X3 (double a, double b, double c, 
			double d, double e, double f, 
			double g, double h, double i);

		VML_EXP X3 (X3 &Matrix3x3);

		double Array [3][3];
	};

	// 4x4 Matrix
	class X4{
	public:

		VML_EXP X4();
		VML_EXP X4 (double a, double b, double c, double d, 
			double e, double f, double g, double h, 
			double i, double j, double k, double l, 
			double m, double n, double o, double p);

		VML_EXP X4 (X4 &Matrix4x4);

		double Array [4][4];
	};

	// Multiply Vector
	VML_EXP Vector2::Point MultiplyVector (X3 Matrix, Vector2::Point Vector);
	VML_EXP Vector3::Point MultiplyVector (X4 Matrix, Vector3::Point Vector);

	// Multiply Matrix
	VML_EXP X3 MultiplyMatrix (X3 Matrix01, X3 Matrix02);
	VML_EXP X4 MultiplyMatrix (X4 Matrix01, X4 Matrix02);

	// Translate Matrix
	VML_EXP Vector2::Point Translate (Vector2::Point Vector);
	VML_EXP Vector3::Point Translate (Vector3::Point Vector);

	// Rotate Matrix
	VML_EXP Vector2::Point Rotate (double rotation, Vector2::Point vector);
	VML_EXP Vector3::Point Rotate (double rotation, Vector3::Point vector, const char axis);

	// Scale Matrix
	VML_EXP Vector2::Point Scale (Vector2::Point scale, Vector2::Point vector);
	VML_EXP Vector3::Point Scale (Vector3::Point scale, Vector3::Point vector);

	// Orthoghrphic Projection
	VML_EXP X4 OrthographicProjection (float right, float left, float top, float bottom, float near, float far);
}

#endif