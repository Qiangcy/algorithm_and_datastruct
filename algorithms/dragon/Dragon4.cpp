#include "Dragon4.h"
#include "Math.h"
#include <math.h>

const tU32 c_BigInt_MaxBlocks = 35;

struct tBigInt
{
    tBigInt & operator=(const tBigInt &rhs)
    {
        tU32 length = rhs.m_length;
        tU32 * pLhsCur = m_blocks;
        for (const tU32 *pRhsCur = rhs.m_blocks, *pRhsEnd = pRhsCur + length;
                pRhsCur != pRhsEnd;
                ++pLhsCur, ++pRhsCur)
        {
            *pLhsCur = *pRhsCur;
        }
        m_length = length;
        return *this;
    }

    tU32 GetLength() const        { return m_length; }
    tU32 GetBlock(tU32 idx) const { return m_blocks[idx]; }

    void    SetZero()       { m_length = 0; }
    tB      IsZero() const  { return m_length == 0; }

    void SetU64(tU64 val) {
        if(val > 0xFFFFFFFF) {
            m_blocks[0] = val & 0xFFFFFFFF;
            m_blocks[1] = (val >> 32) & 0xFFFFFFFF;
            m_length    = 2;
        }else if (val != 0) {
            m_blocks[0] = val & 0xFFFFFFFF;
            m_length    = 1;
        }else {
            m_length = 0;
        }
    }

    void SetU32(tU32 val) {
        if(val != 0) {
            m_blocks[0] = val;
            m_length    = (val != 0);
        }else {
            m_length = 0;
        }
    }

    tU32 GetU32() const { return (m_length == 0) ? 0 : m_blocks[0]; }

    tU32 m_length;
    tU32 m_blocks[c_BigInt_MaxBlocks];
};

static tS32 BigInt_Compare(const tBigInt & lhs, const tBigInt & rhs)
{
    tS32 lengthDiff = lhs.m_length - rhs.m_length;
    if (lengthDiff != 0)
        return lengthDiff;

    for(tS32 i = lhs.m_length - 1; i >= 0; --i) {
        if (lhs.m_blocks[i] == rhs.m_blocks[i])
            continue;
        else if (lhs.m_blocks[i] > rhs.m_blocks[i])
            return 1;
        else
            return -1;
    }

    return 0;
}

static void BigInt_Add(tBigInt * pResult, const tBigInt & lhs, const tBigInt & rhs)
{
    const tBigInt * pLarge;
    const tBigInt * pSmall;
    if(lhs.m_length < rhs.m_length) {
        pSmall = &lhs;
        pLarge = &rhs;
    }else {
        pSmall = &rhs;
        pLarge = &lhs;
    }

    const tU32 largeLen = pLarge->m_length;
    const tU32 smallLen = pSmall->m_length;

    pResult->m_length = largeLen;

    tU64 carry = 0;
    const tU32 * pLargeCur  = pLarge->m_blocks;
    const tU32 * pLargeEnd  = pLargeCur + largeLen;
    const tU32 * pSmallCur  = pSmall->m_blocks;
    const tU32 * pSmallEnd  = pSmallCur + smallLen;
    tU32 *       pResultCur = pResult->m_blocks;
    while(pSmallCur != pSmallEnd) {
        tU64 sum = carry + (tU64)(*pLargeCur) + (tU64)(*pSmallCur);
        carry = sum >> 32;
        (*pResultCur) = sum & 0xFFFFFFFF;
        ++pLargeCur;
        ++pSmallCur;
        ++pResultCur;
    }

    while(pLargeCur != pLargeEnd) {
        tU64 sum = carry + (tU64)(*pLargeCur);
        carry = sum >> 32;
        (*pResultCur) = sum & 0xFFFFFFFF;
        ++pLargeCur;
        ++pResultCur;
    }

    if(carry != 0) {
        RJ_ASSERT(carry == 1);
        RJ_ASSERT((tU32)(pResultCur - pResult->m_blocks) == largeLen && (largeLen < c_BigInt_MaxBlocks));
        *pResultCur = 1;
        pResult->m_length = largeLen + 1;
    }else {
        pResult->m_length = largeLen;
    }
}

static void BigInt_Multiply(tBigInt * pResult, const tBigInt &lhs, const tBigInt &rhs)
{
    RJ_ASSERT( pResult != &lhs && pResult != &rhs );

    const tBigInt * pLarge;
    const tBigInt * pSmall;
    if(lhs.m_length < rhs.m_length) {
        pSmall = &lhs;
        pLarge = &rhs;
    }else {
        pSmall = &rhs;
        pLarge = &lhs;
    }

    tU32 maxResultLen = pLarge->m_length + pSmall->m_length;
    RJ_ASSERT( maxResultLen <= c_BigInt_MaxBlocks );

    for(tU32 * pCur = pResult->m_blocks, *pEnd = pCur + maxResultLen; pCur != pEnd; ++pCur)
        *pCur = 0;

    const tU32 *pLargeBeg = pLarge->m_blocks;
    const tU32 *pLargeEnd = pLargeBeg + pLarge->m_length;

    tU32 *pResultStart = pResult->m_blocks;
    for(const tU32 *pSmallCur = pSmall->m_blocks, *pSmallEnd = pSmallCur + pSmall->m_length;
            pSmallCur != pSmallEnd;
            ++pSmallCur, ++pResultStart) {
        const tU32 multiplier = *pSmallCur;
        if(multiplier != 0) {
            const tU32 *pLargeCur = pLargeBeg;
            tU32 *pResultCur = pResultStart;
            tU64 carry = 0;
            do {
                tU64 product = (*pResultCur) + (*pLargeCur)*(tU64)multiplier + carry;
                carry = product >> 32;
                *pResultCur = product & 0xFFFFFFFF;
                ++pLargeCur;
                ++pResultCur;
            } while(pLargeCur != pLargeEnd);

            RJ_ASSERT(pResultCur < pResult->m_blocks + maxResultLen);
            *pResultCur = (tU32)(carry & 0xFFFFFFFF);
        }
    }

    // check if the terminating block has no set bits
    if(maxResultLen>0 && pResult->m_blocks[maxResultLen-1]==0)
        pResult->m_length = maxResultLen-1;
    else
        pResult->m_length = maxResultLen;
}

static void BigInt_Multiply(tBigInt * pResult, const tBigInt & lhs, tU32 rhs)
{
    tU32 carry = 0;
    tU32 *pResultCur = pResult->m_blocks;
    const tU32 *pLhsCur = lhs.m_blocks;
    const tU32 *pLhsEnd = lhs.m_blocks + lhs.m_length;
    for( ; pLhsCur != pLhsEnd; ++pLhsCur, ++pResultCur) {
        tU64 product = (tU64)(*pLhsCur) * rhs + carry;
        *pResultCur = (tU32)(product & 0xFFFFFFFF);
        carry = product >> 32;
    }

    if(carry != 0) {
        RJ_ASSERT(lhs.m_length + 1 <= c_BigInt_MaxBlocks);
        *pResultCur = (tU32)carry;
        pResult->m_length = lhs.m_length + 1;
    }else {
        pResult->m_length = lhs.m_length;
    }
}

static void BigInt_Multiply2(tBigInt * pResult, const tBigInt &in)
{
    tU32 carry = 0;

    tU32 *pResultCur = pResult->m_blocks;
    const tU32 *pLhsCur = in.m_blocks;
    const tU32 *pLhsEnd = in.m_blocks + in.m_length;
    for( ; pLhsCur != pLhsEnd; ++pLhsCur, ++pResultCur) {
        tU32 cur = *pLhsCur;
        *pResultCur = (cur << 1) | carry;
        carry = cur >> 31;
    }

    if(carry != 0) {
        // grow the array
        RJ_ASSERT(in.m_length + 1 <= c_BigInt_MaxBlocks);
        *pResultCur = carry;
        pResult->m_length = in.m_length + 1;
    }else {
        pResult->m_length = in.m_length;
    }
}

static void BigInt_Multiply2(tBigInt * pResult)
{
    tU32 carry = 0;

    tU32 *pCur = pResult->m_blocks;
    tU32 *pEnd = pResult->m_blocks + pResult->m_length;
    for( ; pCur != pEnd; ++pCur ) {
        tU32 cur = *pCur;
        *pCur = (cur << 1) | carry;
        carry = cur >> 31;
    }

    if(carry != 0) {
        RJ_ASSERT(pResult->m_length + 1 <= c_BigInt_MaxBlocks);
        *pCur = carry;
        ++pResult->m_length;
    }
}

static void BigInt_Multiply10(tBigInt * pResult)
{
    tU64 carry = 0;

    tU32 *pCur = pResult->m_blocks;
    tU32 *pEnd = pResult->m_blocks + pResult->m_length;
    for( ; pCur != pEnd; ++pCur ) {
        tU64 product = (tU64)(*pCur) * 10ull + carry;
        (*pCur) = (tU32)(product & 0xFFFFFFFF);
        carry = product >> 32;
    }

    if(carry != 0) {
        RJ_ASSERT(pResult->m_length + 1 <= c_BigInt_MaxBlocks);
        *pCur = (tU32)carry;
        ++pResult->m_length;
    }
}

static tU32 g_PowerOf10_U32[] =
{
    1,          // 10 ^ 0
    10,         // 10 ^ 1
    100,        // 10 ^ 2
    1000,       // 10 ^ 3
    10000,      // 10 ^ 4
    100000,     // 10 ^ 5
    1000000,    // 10 ^ 6
    10000000,   // 10 ^ 7
};

static tBigInt g_PowerOf10_Big[] =
{
    // 10 ^ 8
    { 1, { 100000000 } },
    // 10 ^ 16
    { 2, { 0x6fc10000, 0x002386f2 } },
    // 10 ^ 32
    { 4, { 0x00000000, 0x85acef81, 0x2d6d415b, 0x000004ee, } },
    // 10 ^ 64
    { 7, { 0x00000000, 0x00000000, 0xbf6a1f01, 0x6e38ed64, 0xdaa797ed, 0xe93ff9f4, 0x00184f03, } },
    // 10 ^ 128
    { 14, { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x2e953e01, 0x03df9909, 0x0f1538fd,
              0x2374e42f, 0xd3cff5ec, 0xc404dc08, 0xbccdb0da, 0xa6337f19, 0xe91f2603, 0x0000024e, } },
    // 10 ^ 256
    { 27, { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
              0x00000000, 0x982e7c01, 0xbed3875b, 0xd8d99f72, 0x12152f87, 0x6bde50c6, 0xcf4a6e70,
              0xd595d80f, 0x26b2716e, 0xadc666b0, 0x1d153624, 0x3c42d35a, 0x63ff540e, 0xcc5573c0,
              0x65f9ef17, 0x55bc28f2, 0x80dcc7f7, 0xf46eeddc, 0x5fdcefce, 0x000553f7, } }
};

static void BigInt_Pow10(tBigInt * pResult, tU32 exponent)
{
    RJ_ASSERT(exponent < 512);

    tBigInt temp1;
    tBigInt temp2;
    tBigInt *pCurTemp = &temp1;
    tBigInt *pNextTemp = &temp2;

    tU32 smallExponent = exponent & 0x7;
    pCurTemp->SetU32(g_PowerOf10_U32[smallExponent]);

    exponent >>= 3;
    tU32 tableIdx = 0;

    while(exponent != 0) {
        if(exponent & 1) {
            BigInt_Multiply( pNextTemp, *pCurTemp, g_PowerOf10_Big[tableIdx] );

            tBigInt * pSwap = pCurTemp;
            pCurTemp = pNextTemp;
            pNextTemp = pSwap;
        }

        ++tableIdx;
        exponent >>= 1;
    }

    *pResult = *pCurTemp;
}

static void BigInt_MultiplyPow10(tBigInt * pResult, const tBigInt & in, tU32 exponent)
{
    RJ_ASSERT(exponent < 512);

    tBigInt temp1;
    tBigInt temp2;
    tBigInt *pCurTemp = &temp1;
    tBigInt *pNextTemp = &temp2;

    tU32 smallExponent = exponent & 0x7;
    if(smallExponent != 0) {
        BigInt_Multiply( pCurTemp, in, g_PowerOf10_U32[smallExponent] );
    }else {
        *pCurTemp = in;
    }

    exponent >>= 3;
    tU32 tableIdx = 0;

    while(exponent != 0) {
        if(exponent & 1) {
            BigInt_Multiply(pNextTemp, *pCurTemp, g_PowerOf10_Big[tableIdx]);

            tBigInt * pSwap = pCurTemp;
            pCurTemp = pNextTemp;
            pNextTemp = pSwap;
        }

        ++tableIdx;
        exponent >>= 1;
    }

    *pResult = *pCurTemp;
}

static inline void BigInt_Pow2(tBigInt * pResult, tU32 exponent)
{
    tU32 blockIdx = exponent / 32;
    RJ_ASSERT( blockIdx < c_BigInt_MaxBlocks ); 

    for( tU32 i = 0; i <= blockIdx; ++i)
        pResult->m_blocks[i] = 0;

    pResult->m_length = blockIdx + 1;

    tU32 bitIdx = (exponent % 32);
    pResult->m_blocks[blockIdx] |= (1 << bitIdx);
}

static tU32 BigInt_DivideWithRemainder_MaxQuotient9(tBigInt * pDividend, const tBigInt & divisor)
{
    RJ_ASSERT(  !divisor.IsZero() &&
            divisor.m_blocks[divisor.m_length-1] >= 8 &&
            divisor.m_blocks[divisor.m_length-1] < 0xFFFFFFFF &&
            pDividend->m_length <= divisor.m_length );

    tU32 length = divisor.m_length;
    if(pDividend->m_length < divisor.m_length)
        return 0;

    const tU32 * pFinalDivisorBlock  = divisor.m_blocks + length - 1;           
    tU32 *       pFinalDividendBlock = pDividend->m_blocks + length - 1;

    tU32  quotient = *pFinalDividendBlock / (*pFinalDivisorBlock + 1);
    RJ_ASSERT(quotient <= 9);

    if(quotient != 0) {
        const tU32 *pDivisorCur = divisor.m_blocks;
        tU32 *pDividendCur      = pDividend->m_blocks;

        tU64 borrow = 0;
        tU64 carry = 0;
        do {
            tU64 product = (tU64)*pDivisorCur * (tU64)quotient + carry;
            carry = product >> 32;

            tU64 difference = (tU64)*pDividendCur - (product & 0xFFFFFFFF) - borrow;
            borrow = (difference >> 32) & 1;

            *pDividendCur = difference & 0xFFFFFFFF;

            ++pDivisorCur;
            ++pDividendCur;
        } while(pDivisorCur <= pFinalDivisorBlock);

        while(length > 0 && pDividend->m_blocks[length - 1] == 0)
            --length;

        pDividend->m_length = length;
    }

    if(BigInt_Compare(*pDividend, divisor) >= 0) {
        ++quotient;

        const tU32 *pDivisorCur = divisor.m_blocks;
        tU32 *pDividendCur      = pDividend->m_blocks;

        tU64 borrow = 0;
        do {
            tU64 difference = (tU64)*pDividendCur - (tU64)*pDivisorCur - borrow;
            borrow = (difference >> 32) & 1;

            *pDividendCur = difference & 0xFFFFFFFF;

            ++pDivisorCur;
            ++pDividendCur;
        } while(pDivisorCur <= pFinalDivisorBlock);

        while (length > 0 && pDividend->m_blocks[length - 1] == 0)
            --length;

        pDividend->m_length = length;
    }

    return quotient;
}

static void BigInt_ShiftLeft(tBigInt * pResult, tU32 shift)
{
    RJ_ASSERT( shift != 0 );

    tU32 shiftBlocks = shift / 32;
    tU32 shiftBits = shift % 32;

    const tU32 *    pInBlocks   = pResult->m_blocks;
    tS32            inLength    = pResult->m_length;
    RJ_ASSERT( inLength + shiftBlocks < c_BigInt_MaxBlocks );

    if(shiftBits == 0) {
        for (tU32 * pInCur = pResult->m_blocks + inLength, *pOutCur = pInCur + shiftBlocks;
                pInCur >= pInBlocks;
                --pInCur, --pOutCur) {
            *pOutCur = *pInCur;
        }

        for( tU32 i = 0; i < shiftBlocks; ++i)
            pResult->m_blocks[i] = 0;

        pResult->m_length += shiftBlocks;
    }else {
        tS32 inBlockIdx  = inLength - 1;
        tU32 outBlockIdx = inLength + shiftBlocks;

        RJ_ASSERT( outBlockIdx < c_BigInt_MaxBlocks );
        pResult->m_length = outBlockIdx + 1;

        const tU32 lowBitsShift = (32 - shiftBits);
        tU32 highBits = 0;
        tU32 block = pResult->m_blocks[inBlockIdx];              
        tU32 lowBits = block >> lowBitsShift;
        while(inBlockIdx > 0) {
            pResult->m_blocks[outBlockIdx] = highBits | lowBits;
            highBits = block << shiftBits;

            --inBlockIdx;
            --outBlockIdx;

            block = pResult->m_blocks[inBlockIdx];
            lowBits = block >> lowBitsShift;
        }

        RJ_ASSERT( outBlockIdx == shiftBlocks + 1 );
        pResult->m_blocks[outBlockIdx] = highBits | lowBits;
        pResult->m_blocks[outBlockIdx-1] = block << shiftBits;

        for( tU32 i = 0; i < shiftBlocks; ++i)
            pResult->m_blocks[i] = 0;

        if(pResult->m_blocks[pResult->m_length-1] == 0)
            --pResult->m_length;
    }
}

tU32 Dragon4 (const tU64 mantissa, const tS32 exponent, const tU32 mantissaHighBitIdx,
        const tB hasUnequalMargins, const tCutoffMode cutoffMode, tU32 cutoffNumber,
        tC8 *pOutBuffer, tU32 bufferSize, tS32 *pOutExponent)
{
    tC8 * pCurDigit = pOutBuffer;

    RJ_ASSERT( bufferSize > 0 );

    if(mantissa == 0) {
        *pCurDigit = '0';
        *pOutExponent = 0;
        return 1;
    }

    tBigInt scale;              // positive scale applied to value and margin such that they can be
    //  represented as whole numbers
    tBigInt scaledValue;        // scale * mantissa
    tBigInt scaledMarginLow;    // scale * 0.5 * (distance between this floating-point number and its
    //  immediate lower value)

    tBigInt * pScaledMarginHigh;
    tBigInt optionalMarginHigh;

    if(hasUnequalMargins) {
        if(exponent > 0) {
            scaledValue.SetU64( 4 * mantissa );
            BigInt_ShiftLeft( &scaledValue, exponent );

            scale.SetU32( 4 );

            BigInt_Pow2( &scaledMarginLow, exponent );

            BigInt_Pow2( &optionalMarginHigh, exponent + 1 );
        }else {
            scaledValue.SetU64( 4 * mantissa ); 

            BigInt_Pow2(&scale, -exponent + 2 );

            scaledMarginLow.SetU32( 1 );

            optionalMarginHigh.SetU32( 2 );
        }

        pScaledMarginHigh = &optionalMarginHigh;
    }else {
        if(exponent > 0) {
            scaledValue.SetU64( 2 * mantissa );
            BigInt_ShiftLeft( &scaledValue, exponent );

            scale.SetU32( 2 );

            BigInt_Pow2( &scaledMarginLow, exponent );
        }else {
            scaledValue.SetU64( 2 * mantissa );

            BigInt_Pow2(&scale, -exponent + 1 );

            scaledMarginLow.SetU32( 1 );
        }

        pScaledMarginHigh = &scaledMarginLow;
    }

    const tF64 log10_2 = 0.30102999566398119521373889472449;
    tS32 digitExponent = (tS32)(ceil(tF64((tS32)mantissaHighBitIdx + exponent) * log10_2 - 0.69));

    if(cutoffMode==CutoffMode_FractionLength && digitExponent<=-(tS32)cutoffNumber) {
        digitExponent = -(tS32)cutoffNumber + 1;
    }

    if(digitExponent > 0) {
        tBigInt temp;
        BigInt_MultiplyPow10( &temp, scale, digitExponent );
        scale = temp;
    }else if (digitExponent < 0) {
        tBigInt pow10;
        BigInt_Pow10( &pow10, -digitExponent);

        tBigInt temp;
        BigInt_Multiply( &temp, scaledValue, pow10);
        scaledValue = temp;

        BigInt_Multiply( &temp, scaledMarginLow, pow10);
        scaledMarginLow = temp;

        if (pScaledMarginHigh != &scaledMarginLow)
            BigInt_Multiply2( pScaledMarginHigh, scaledMarginLow );
    }

    tBigInt scaledValueHigh;
    BigInt_Add( &scaledValueHigh, scaledValue, *pScaledMarginHigh );
    if(BigInt_Compare(scaledValueHigh,scale) >= 0) {
        digitExponent = digitExponent + 1;
    }else {
        BigInt_Multiply10( &scaledValue );
        BigInt_Multiply10( &scaledMarginLow );
        if (pScaledMarginHigh != &scaledMarginLow)
            BigInt_Multiply2( pScaledMarginHigh, scaledMarginLow );
    }

    tS32 cutoffExponent = digitExponent - bufferSize;
    switch(cutoffMode) {
        case CutoffMode_Unique:
            break;

        case CutoffMode_TotalLength: {
                                         tS32 desiredCutoffExponent = digitExponent - (tS32)cutoffNumber;
                                         if (desiredCutoffExponent > cutoffExponent)
                                             cutoffExponent = desiredCutoffExponent;
                                     }
                                     break;

        case CutoffMode_FractionLength: {
                                            tS32 desiredCutoffExponent = -(tS32)cutoffNumber;
                                            if (desiredCutoffExponent > cutoffExponent)
                                                cutoffExponent = desiredCutoffExponent;
                                        }
                                        break;
    }

    *pOutExponent = digitExponent-1;

    RJ_ASSERT( scale.GetLength() > 0 );
    tU32 hiBlock = scale.GetBlock( scale.GetLength() - 1 );
    if(hiBlock < 8 || hiBlock > 429496729) {
        tU32 hiBlockLog2 = LogBase2(hiBlock);
        RJ_ASSERT(hiBlockLog2 < 3 || hiBlockLog2 > 27);
        tU32 shift = (32 + 27 - hiBlockLog2) % 32;

        BigInt_ShiftLeft( &scale, shift );
        BigInt_ShiftLeft( &scaledValue, shift);
        BigInt_ShiftLeft( &scaledMarginLow, shift);
        if (pScaledMarginHigh != &scaledMarginLow)
            BigInt_Multiply2( pScaledMarginHigh, scaledMarginLow );
    }

    tB      low;            // did the value get within marginLow distance from zero
    tB      high;           // did the value get within marginHigh distance from one
    tU32    outputDigit;    // current digit being output

    if(cutoffMode == CutoffMode_Unique) {
        for(;;) {
            digitExponent = digitExponent-1;

            outputDigit = BigInt_DivideWithRemainder_MaxQuotient9(&scaledValue, scale);
            RJ_ASSERT( outputDigit < 10 );

            BigInt_Add( &scaledValueHigh, scaledValue, *pScaledMarginHigh );

            low = BigInt_Compare(scaledValue, scaledMarginLow) < 0;
            high = BigInt_Compare(scaledValueHigh, scale) > 0;
            if (low | high | (digitExponent == cutoffExponent))
                break;

            *pCurDigit = (tC8)('0' + outputDigit);
            ++pCurDigit;

            BigInt_Multiply10( &scaledValue );
            BigInt_Multiply10( &scaledMarginLow );
            if (pScaledMarginHigh != &scaledMarginLow)
                BigInt_Multiply2( pScaledMarginHigh, scaledMarginLow );
        }
    }else {
        low = false;
        high = false;

        for(;;) {
            digitExponent = digitExponent-1;

            outputDigit = BigInt_DivideWithRemainder_MaxQuotient9(&scaledValue, scale);
            RJ_ASSERT( outputDigit < 10 );

            if(scaledValue.IsZero() | (digitExponent==cutoffExponent))
                break;

            *pCurDigit = (tC8)('0' + outputDigit);
            ++pCurDigit;

            BigInt_Multiply10(&scaledValue);
        }
    }

    tB roundDown = low;

    if(low == high) {
        BigInt_Multiply2(&scaledValue);
        tS32 compare = BigInt_Compare(scaledValue, scale);
        roundDown = compare < 0;

        if(compare == 0)
            roundDown = 1;//(outputDigit & 1) == 0;
    }

    if(roundDown) {
        *pCurDigit = (tC8)('0' + outputDigit);
        ++pCurDigit;
    }else {
        if(outputDigit == 9) {
            for(;;) {
                if(pCurDigit == pOutBuffer) {
                    *pCurDigit = '1';
                    ++pCurDigit;
                    *pOutExponent += 1;
                    break;
                }

                --pCurDigit;
                if(*pCurDigit != '9') {
                    *pCurDigit += 1;
                    ++pCurDigit;
                    break;
                }
            }
        }else {
            *pCurDigit = (tC8)('0' + outputDigit + 1);
            ++pCurDigit;
        }
    }

    RJ_ASSERT(pCurDigit - pOutBuffer <= (tPtrDiff)bufferSize);
    return pCurDigit - pOutBuffer;
}
