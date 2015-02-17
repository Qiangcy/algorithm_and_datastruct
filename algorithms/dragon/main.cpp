#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Standard.h"
#include "Dragon4.h"
#include "Math.h"

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
enum tPrintFloatFormat
{
    PrintFloatFormat_Positional,    // [-]ddddd.dddd
    PrintFloatFormat_Scientific,    // [-]d.dddde[sign]ddd
};
union tFloatUnion64
{
    tB   IsNegative() const  { return (m_integer >> 63) != 0; }
    tU32 GetExponent() const { return (m_integer >> 52) & 0x7FF; }
    tU64 GetMantissa() const { return m_integer & 0xFFFFFFFFFFFFFull; }

    tF64 m_floatingPoint;
    tU64 m_integer;
};
tU32 PrintFloat64(tC8 *pOutBuffer, tU32 bufferSize, tF64 value,
        tPrintFloatFormat format, tS32 precision);

int main()
{
	const tU32 valBuffSize = 2048;
	tC8 valBuff[valBuffSize];
	tU32 printLen = PrintFloat64(valBuff, valBuffSize, 3.14159265358979323846, PrintFloatFormat_Scientific, 10);
    printf("result is %s \n", valBuff);
    printf("num is %d \n", printLen);
    return 0;

}


tU32 FormatPositional(tC8 *pOutBuffer, tU32 bufferSize, tU64 mantissa,
        tS32 exponent,tU32 mantissaHighBitIdx, tB hasUnequalMargins, tS32 precision)
{
    RJ_ASSERT(bufferSize > 0);

    tS32 printExponent;
    tU32 numPrintDigits;

    tU32 maxPrintLen = bufferSize - 1;

    if(precision < 0) {
        numPrintDigits = Dragon4(mantissa, exponent, mantissaHighBitIdx,
                hasUnequalMargins, CutoffMode_Unique, 0,
                pOutBuffer, maxPrintLen, &printExponent );
    }else {
        numPrintDigits = Dragon4(mantissa, exponent, mantissaHighBitIdx,
                hasUnequalMargins, CutoffMode_FractionLength, precision,
                pOutBuffer, maxPrintLen, &printExponent );
    }

    RJ_ASSERT( numPrintDigits > 0 );
    RJ_ASSERT( numPrintDigits <= bufferSize );

    tU32 numFractionDigits = 0;

    if(printExponent >= 0) {
        tU32 numWholeDigits = printExponent+1;
        if(numPrintDigits < numWholeDigits) {
            if (numWholeDigits > maxPrintLen)
                numWholeDigits = maxPrintLen;

            for ( ; numPrintDigits < numWholeDigits; ++numPrintDigits )
                pOutBuffer[numPrintDigits] = '0';
        }else if(numPrintDigits > (tU32)numWholeDigits) {
            numFractionDigits = numPrintDigits - numWholeDigits;
            tU32 maxFractionDigits = maxPrintLen - numWholeDigits - 1;
            if(numFractionDigits > maxFractionDigits)
                numFractionDigits = maxFractionDigits;

            memmove(pOutBuffer + numWholeDigits + 1, pOutBuffer + numWholeDigits, numFractionDigits);
            pOutBuffer[numWholeDigits] = '.';
            numPrintDigits = numWholeDigits + 1 + numFractionDigits;
        }
    }else {
        if(maxPrintLen > 2) {
            tU32 numFractionZeros = (tU32)-printExponent - 1;
            tU32 maxFractionZeros = maxPrintLen - 2;
            if(numFractionZeros > maxFractionZeros)
                numFractionZeros = maxFractionZeros;

            tU32 digitsStartIdx = 2 + numFractionZeros;

            numFractionDigits = numPrintDigits;
            tU32 maxFractionDigits = maxPrintLen - digitsStartIdx;
            if(numFractionDigits > maxFractionDigits)
                numFractionDigits = maxFractionDigits;

            memmove(pOutBuffer + digitsStartIdx, pOutBuffer, numFractionDigits);

            for(tU32 i = 2; i < digitsStartIdx; ++i)
                pOutBuffer[i] = '0';

            numFractionDigits += numFractionZeros;
            numPrintDigits = numFractionDigits;
        }

        if(maxPrintLen > 1) {
            pOutBuffer[1] = '.';
            numPrintDigits += 1;
        }

        if(maxPrintLen > 0) {
            pOutBuffer[0] = '0';
            numPrintDigits += 1;
        }
    }

    if(precision>(tS32)numFractionDigits && numPrintDigits<maxPrintLen) {
        if(numFractionDigits == 0) {
            pOutBuffer[numPrintDigits++] = '.';
        }

        tU32 totalDigits = numPrintDigits + (precision-numFractionDigits);
        if(totalDigits > maxPrintLen)
            totalDigits = maxPrintLen;

        for( ; numPrintDigits < totalDigits; ++numPrintDigits)
            pOutBuffer[numPrintDigits] = '0';
    }

    RJ_ASSERT( numPrintDigits <= maxPrintLen );
    pOutBuffer[numPrintDigits] = '\0';

    return numPrintDigits;
}

tU32 FormatScientific(tC8 *pOutBuffer, tU32 bufferSize, tU64 mantissa,
        tS32 exponent, tU32 mantissaHighBitIdx, tB hasUnequalMargins, tS32 precision)
{
    RJ_ASSERT(bufferSize > 0);

    tS32 printExponent;
    tU32 numPrintDigits;

    if(precision < 0) {
        numPrintDigits = Dragon4(mantissa, exponent, mantissaHighBitIdx, hasUnequalMargins,
                CutoffMode_Unique, 0, pOutBuffer, bufferSize, &printExponent );
    }else {
        numPrintDigits = Dragon4(mantissa, exponent, mantissaHighBitIdx, hasUnequalMargins,
                CutoffMode_TotalLength, precision + 1, pOutBuffer, bufferSize, &printExponent );
    }

    RJ_ASSERT( numPrintDigits > 0 );
    RJ_ASSERT( numPrintDigits <= bufferSize );

    tC8 * pCurOut = pOutBuffer;

    if(bufferSize > 1) {
        pCurOut += 1;
        bufferSize -= 1;
    }

    tU32 numFractionDigits = numPrintDigits-1;
    if(numFractionDigits>0 && bufferSize>1) {
        tU32 maxFractionDigits = bufferSize-2;
        if(numFractionDigits > maxFractionDigits)
            numFractionDigits =  maxFractionDigits;

        memmove(pCurOut + 1, pCurOut, numFractionDigits);
        pCurOut[0] = '.';
        pCurOut += (1 + numFractionDigits);
        bufferSize -= (1 + numFractionDigits);
    }

    if(precision>(tS32)numFractionDigits && bufferSize>1) {
        if(numFractionDigits == 0) {
            *pCurOut = '.';
            ++pCurOut;
            --bufferSize;
        }

        tU32 numZeros = (precision - numFractionDigits);
        if(numZeros > bufferSize-1)
            numZeros = bufferSize-1;

        for(tC8 * pEnd = pCurOut + numZeros; pCurOut < pEnd; ++pCurOut)
            *pCurOut = '0';
    }

    if(bufferSize > 1) {
        tC8 exponentBuffer[5];
        exponentBuffer[0] = 'e';
        if(printExponent >= 0) {
            exponentBuffer[1] = '+';
        }else {
            exponentBuffer[1] = '-';
            printExponent = -printExponent;
        }

        RJ_ASSERT(printExponent < 1000);
        tU32 hundredsPlace  = printExponent / 100;
        tU32 tensPlace      = (printExponent - hundredsPlace*100) / 10;
        tU32 onesPlace      = (printExponent - hundredsPlace*100 - tensPlace*10);

        exponentBuffer[2] = (tC8)('0' + hundredsPlace);
        exponentBuffer[3] = (tC8)('0' + tensPlace);
        exponentBuffer[4] = (tC8)('0' + onesPlace);

        tU32 maxExponentSize = bufferSize-1;
        tU32 exponentSize = (5 < maxExponentSize) ? 5 : maxExponentSize;
        memcpy( pCurOut, exponentBuffer, exponentSize );

        pCurOut += exponentSize;
        bufferSize -= exponentSize;
    }

    RJ_ASSERT( bufferSize > 0 );
    pCurOut[0] = '\0';

    return pCurOut - pOutBuffer;
}

static tU32 PrintInfNan(tC8 * pOutBuffer, tU32 bufferSize, tU64 mantissa, tU32 mantissaHexWidth)
{
    RJ_ASSERT(bufferSize > 0);

    tU32 maxPrintLen = bufferSize-1;

    if(mantissa == 0) {
        tU32 printLen = (3 < maxPrintLen) ? 3 : maxPrintLen;
        ::memcpy( pOutBuffer, "Inf", printLen );
        pOutBuffer[printLen] = '\0';
        return printLen;
    }else {
        tU32 printLen = (3 < maxPrintLen) ? 3 : maxPrintLen;
        ::memcpy( pOutBuffer, "NaN", printLen );
        pOutBuffer[printLen] = '\0';

        if (maxPrintLen > 3)
        ;//    printLen += PrintHex(pOutBuffer+3, bufferSize-3, mantissa, mantissaHexWidth);

        return printLen;
    }
}

tU32 PrintFloat64(tC8 *pOutBuffer, tU32 bufferSize, tF64 value,
        tPrintFloatFormat format, tS32 precision)
{
    if(bufferSize == 0)
        return 0;

    if(bufferSize == 1) {
        pOutBuffer[0] = '\0';
        return 0;
    }

    tFloatUnion64 floatUnion;
    floatUnion.m_floatingPoint = value;
    tU32 floatExponent = floatUnion.GetExponent();
    tU64 floatMantissa = floatUnion.GetMantissa();
    tU32 prefixLength = 0;
    if(floatUnion.IsNegative()) {
        pOutBuffer[0] = '-';
        ++pOutBuffer;
        --bufferSize;
        ++prefixLength;
        RJ_ASSERT(bufferSize > 0);
    }

    if (floatExponent == 0x7FF) {
        return PrintInfNan(pOutBuffer, bufferSize, floatMantissa, 13) + prefixLength;
    }else {
        tU64 mantissa;
        tS32 exponent;
        tU32 mantissaHighBitIdx;
        tB hasUnequalMargins;

        if(floatExponent != 0) {
            mantissa            = (1ull << 52) | floatMantissa;
            exponent            = floatExponent - 1023 - 52;
            mantissaHighBitIdx  = 52;
            hasUnequalMargins   = (floatExponent != 1) && (floatMantissa == 0);//why?
        }else {
            mantissa            = floatMantissa;
            exponent            = 1 - 1023 - 52;
            mantissaHighBitIdx  = LogBase2(mantissa);
            hasUnequalMargins   = false;
        }
        switch (format) {
            case PrintFloatFormat_Positional:
                return FormatPositional(pOutBuffer, bufferSize, mantissa,
                        exponent, mantissaHighBitIdx, hasUnequalMargins,
                        precision ) + prefixLength;

            case PrintFloatFormat_Scientific:
                return FormatScientific(pOutBuffer, bufferSize, mantissa,
                        exponent, mantissaHighBitIdx, hasUnequalMargins,
                        precision ) + prefixLength;

            default:
                pOutBuffer[0] = '\0';
                return 0;
        }
    }
}

