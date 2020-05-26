//
// Created by dreamcxy on 2020/5/25.
//

#include <cstring>
#include "../bitmap.h"

#define MASK 0x3f      // 2^6=64
#define SHIFT 6
#define INT_BITS_LENGTH sizeof(uint64_t)

// nDivisor/nDividend 向上取整
inline uint32_t RoundUp(uint32_t nDivisor, uint32_t nDividend)
{
    return (nDivisor + nDividend - 1) / nDividend;
}

// nDivisor/nDividend 向下取整
inline uint32_t RoundDown(uint32_t nDivisor, uint32_t nDividend)
{
    return nDivisor / nDividend;
}


CBitMap::CBitMap(uint32_t nCapacity)
{
    m_nCapacity = nCapacity;
    m_nRealBitLen = RoundUp(nCapacity, INT_BITS_LENGTH);
    m_arrBits = new uint64_t[m_nRealBitLen];

}

int32_t CBitMap::SetBit(uint64_t nIndex)
{
    if (nIndex > m_nCapacity)
    {
        return -1;
    }
    uint32_t nOffset = nIndex & MASK;
    uint32_t nCardinality = RoundDown(nIndex, INT_BITS_LENGTH);
    return 0;
}

int32_t CBitMap::GetBit(uint64_t nIndex)
{
    if (nIndex > m_nCapacity)
    {
        return -1;
    }
    return
}


int32_t CBitMap::Clear()
{
    memset(m_arrBits, 0, m_nRealBitLen);
    return 0;
}
