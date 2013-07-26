#ifndef CONVERTER_H
#define CONVERTER_H

#ifndef VML_EXP
#define VML_EXP __declspec (dllexport)
#endif

#include <string>

namespace Convert{

	VML_EXP std::string DecConvert (long long decimal, int baseValue);
	VML_EXP int BinToDec (long long binaryValue);
	VML_EXP int HexToDec (std::string hexValue);
	VML_EXP long long HexToBin (std::string hexValue);
	VML_EXP std::string BinToHex (long long binValue);
}

#endif