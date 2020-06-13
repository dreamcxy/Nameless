//
// Created by chenxiaoyu5 on 2020/6/12.
//

#include <iostream>
using namespace std;

const int INT_SIZE = sizeof(int)*8; // int类型整数的位数
const int MAX_HEIGHT_FLAG = 1 << (INT_SIZE - 1); // 用于取最高位

// 取一个整数的二进制形式字符串，参数一为该整数，参数二为字符串数组首地址
void Int2Binary(int num, char* str){

    // 如果是负数，需要先求出原码
    if (num<0)
    {
        // 计算机中存储的是数字的补码（取反+1）
        num = ~(num - 1 ); //求原码（-1，取反）
        num |= MAX_HEIGHT_FLAG; //负数最高位为1
    }

    // 每次循环使数字左移i位，并取最高位
    char val = 0;
    for (int i=1; i<=INT_SIZE; ++i)
    {
        val = MAX_HEIGHT_FLAG&num << (i-1) ? '1' : '0'; //左移并取最高位，如果当前最高位为1则val值为'1'，否则为'0'
        str[i-1] = val;

        printf("%c", val);
        if (i%4==0)
        {
            printf(" ");
        }
    }
    str[INT_SIZE] = 0; //结束符
    printf("\n");
}


int main()
{

    int32_t nMax = 100;
    int32_t nIndex = nMax / 32 + 1;


    int32_t arr[4] = {0};
    int32_t nAmount = 100;

    int32_t nBase = ((nAmount - 1) % nMax) / 32;
    int32_t nOffset = ((nAmount -1) % nMax) % 32;

    char str[INT_SIZE + 1];

    // 原来的位置
    for (int i = 0; i < nIndex; ++i)
    {
        Int2Binary(arr[i], str);
    }


    int32_t nValue = arr[nBase] | (1 << nOffset);
    arr[nBase] = nValue;

    cout << "===================================================" << endl;
    // 后来的位置
    for (int i = 0; i < nIndex; ++i)
    {
        Int2Binary(arr[i], str);
    }


    cout << "===================================================" << endl;

    Int2Binary(5, str);

}
