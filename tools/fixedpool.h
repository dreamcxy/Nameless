//
// Created by dreamcxy on 2020/5/1.
// 利用数组管理固定大小的内存池
//

#pragma once

#ifndef NAMELESS_FIXEDPOOL_H
#define NAMELESS_FIXEDPOOL_H

#include <cstdint>

template <class T, int32_t nPoolSize>
class CFixedPool
{
private:
    struct STSlot
    {
        T m_oEleMent;
        bool m_nUsed;
        int32_t m_nIndex;
    };

public:
    CFixedPool() {}
    ~CFixedPool() {}

public:
    int32_t FreeOneElement(T *pElement);
    int32_t AddOneElement(T* pElement);
    int32_t GetCapacity();
    int32_t GetUesdSize();

private:
    int32_t nSize;
    int32_t nUsedSize;
    T m_arr[nPoolSize];

};






#endif //NAMELESS_FIXEDPOOL_H
