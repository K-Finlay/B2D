#ifndef MATH_H
#define MATH_H

#include <cmath>

#ifndef PI
#define PI 3.1415926535
#endif

namespace Math{

     double DegreesToRadians (double value);
     double RadianToDegrees (double value);
     float ScalerLerp (float pointA, float pointB, float value);
     bool GetPowerOfTwo (int value);
}

#endif
