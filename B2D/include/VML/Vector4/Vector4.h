#ifndef VECTOR4_H
#define VECTOR4_H

#include "../Converter/Converter.h"
#include <iostream>
#include <string>

#ifndef VML_EXP
#define VML_EXP __declspec (dllexport)
#endif

namespace Vector4{

	class Point{
	public:

		float x, y, z, w;

		VML_EXP void SetPoint (float xPoint, float yPoint, float zPoint, float wPoint){

			x = xPoint;
			y = yPoint;
			z = zPoint;
			w = wPoint;
		}
	};

	VML_EXP float Magnitude (Point startPoint, Point endPoint);
	VML_EXP Point Normalize (Point startPoint, Point endPoint);
	VML_EXP Point Lerp (Point vectorA, Point vectorB, float value);
}

class RGBA{
public:

	VML_EXP RGBA();
	VML_EXP RGBA (float r, float g, float b, float a){

		colour.x = r;
		colour.y = g;
		colour.z = b;
		colour.w = a;
	}

	VML_EXP RGBA (const char* HexValue){

		std::string value;

		// Set R
		value = HexValue[0];
		value += HexValue[1];
		colour.x = ((float) Convert::HexToDec (value)) / 255;

		// Set G
		value = HexValue[2];
		value += HexValue[3];
		colour.y = ((float) Convert::HexToDec (value)) / 255;

		// Set B
		value = HexValue[4];
		value += HexValue[5];
		colour.z = ((float) Convert::HexToDec (value)) / 255;

		// Set A
		value = HexValue[6];
		value += HexValue[7];
		colour.w = ((float) Convert::HexToDec (value)) / 255;
	}

	Vector4::Point colour;
};

#endif