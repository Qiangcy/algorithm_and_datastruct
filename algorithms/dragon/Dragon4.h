#ifndef RJ__Dragon4_h
#define RJ__Dragon4_h

#include "Standard.h"

enum tCutoffMode
{
    CutoffMode_Unique,          // as many digits as necessary to print a uniquely identifiable number
    CutoffMode_TotalLength,     // up to cutoffNumber significant digits
    CutoffMode_FractionLength,  // up to cutoffNumber significant digits past the decimal point
};

tU32 Dragon4
(
    tU64        mantissa,           // value significand
    tS32        exponent,           // value exponent in base 2
    tU32        mantissaHighBitIdx, // index of the highest set mantissa bit
    tB          hasUnequalMargins,  // is the high margin twice as large as the low margin
    tCutoffMode cutoffMode,         // how to determine output length
    tU32        cutoffNumber,       // parameter to the selected cutoffMode
    tC8 *       pOutBuffer,         // buffer to output into
    tU32        bufferSize,         // maximum characters that can be printed to pOutBuffer
    tS32 *      pOutExponent        // the base 10 exponent of the first digit
);

#endif
