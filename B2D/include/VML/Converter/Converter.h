#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>

namespace Convert{

     std::string DecConvert (long long decimal, int baseValue);
     int BinToDec (long long binaryValue);
     int HexToDec (std::string hexValue);
     long long HexToBin (std::string hexValue);
     std::string BinToHex (long long binValue);
}

#endif
