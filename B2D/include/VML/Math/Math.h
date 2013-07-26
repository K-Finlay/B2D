#ifndef MATH_H
#define MATH_H

#ifndef VML_EXP
#define VML_EXP __declspec (dllexport)
#endif

#include <cmath>

#ifndef PI
#define PI 3.1415926535
#endif

namespace Math{

	VML_EXP double DegreesToRadians (double value);
	VML_EXP double RadianToDegrees (double value);
	VML_EXP float ScalerLerp (float pointA, float pointB, float value);
	VML_EXP bool GetPowerOfTwo (int value);
}

#endif