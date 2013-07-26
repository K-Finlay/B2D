#ifndef BITWISE_H
#define BITWISE_H

namespace Bitwise{

	int ShiftLeft (int valueToShift, int placesToShift);
	int ShiftRight (int valueToShift, int placesToShift);
	int BitAnd (int value01, int value02);
	int BitOr (int value01, int value02);
	int BitXOr (int value01, int value02);
	int FlipBits (int value);
}

#endif