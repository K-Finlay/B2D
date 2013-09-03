#ifndef MATRIX_H
#define MATRIX_H

#include "../Vector2/Vector2.h"
#include "../Vector3/Vector3.h"
#include "../Math/Math.h"

namespace Matrix{

	// 3x3 Matrix
	class X3{
	public:

         X3();
         X3 (double a, double b, double c,
			double d, double e, double f, 
			double g, double h, double i);

         X3 (X3 &Matrix3x3);

		double Array [3][3];
	};

	// 4x4 Matrix
	class X4{
	public:

         X4();
         X4 (double a, double b, double c, double d,
			double e, double f, double g, double h, 
			double i, double j, double k, double l, 
			double m, double n, double o, double p);

         X4 (X4 &Matrix4x4);

		double Array [4][4];
	};

	// Multiply Vector
     Vector2::Point MultiplyVector (X3 Matrix, Vector2::Point Vector);
     Vector3::Point MultiplyVector (X4 Matrix, Vector3::Point Vector);

	// Multiply Matrix
     X3 MultiplyMatrix (X3 Matrix01, X3 Matrix02);
     X4 MultiplyMatrix (X4 Matrix01, X4 Matrix02);

	// Translate Matrix
     Vector2::Point Translate (Vector2::Point Vector);
     Vector3::Point Translate (Vector3::Point Vector);

	// Rotate Matrix
     Vector2::Point Rotate (double rotation, Vector2::Point vector);
     Vector3::Point Rotate (double rotation, Vector3::Point vector, const char axis);

	// Scale Matrix
     Vector2::Point Scale (Vector2::Point scale, Vector2::Point vector);
     Vector3::Point Scale (Vector3::Point scale, Vector3::Point vector);

	// Orthoghrphic Projection
     X4 OrthographicProjection (float right, float left, float top, float bottom, float near, float far);
}

#endif
