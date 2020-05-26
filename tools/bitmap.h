//
// Created by chenxiaoyu5 on 2020/5/5.
//

#ifndef NAMELESS_BITMAP_H
#define NAMELESS_BITMAP_H

#include <cstdint>

class CBitMap
{
public:
    CBitMap() = default;
    CBitMap(uint32_t nCapacity);
    ~CBitMap()
    {
        if (m_arrBits)
        {
            delete[] m_arrBits;
        }
    }


    int32_t Initialize(uint32_t nSize);

    // 设置第nIndex位
    int32_t SetBit(uint64_t nIndex);
    // 获取第nIndex位
    int32_t GetBit(uint64_t nIndex);
    // 清除第nIndex位
    int32_t Clear();

    inline uint64_t GetCapacity() {return m_nCapacity;}

private:
    uint32_t m_nCapacity;    // 代表传进来的数组长度
    uint32_t m_nRealBitLen;  // 代表实际需要的位图长度
    uint64_t *m_arrBits;     // 存储用的数组

};

#endif //NAMELESS_BITMAP_H
