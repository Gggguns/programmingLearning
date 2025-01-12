#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aes.h"

/**
 * S盒（Substitution box）：用于字节代换的查找表。
 * S盒是一个16x16的二维数组，每个元素是一个8位的无符号字符。
 * 用于将输入的字节替换为另一个字节，增加算法的非线性。
 */
static const unsigned char S[16][16] = { 
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 };

/**
 * 逆S盒（Inverse Substitution box）：用于逆字节代换的查找表。
 * 逆S盒也是一个16x16的二维数组，每个元素是一个8位的无符号字符。
 * 用于将加密过程中替换的字节还原回原来的字节。
 */
static const unsigned char S2[16][16] = { 
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d };


/**
 * 根据索引，从S盒中获得元素
 */
static int getNumFromSBox(unsigned char index) 
{
    return S[index>>4][index&0x0f];
}

/**
 * 把一个字符转变成4字节整型
 */
static unsigned long getIntFromChar(unsigned char c) 
{
    unsigned long result = (unsigned long) c;
    return result & 0x000000ff;
}

/**
 * 把16个字符转变成4X4的数组，
 * 该矩阵中字节的排列顺序为从上到下，
 * 从左到右依次排列。
 */
static void convertToIntArray(unsigned char *str, unsigned char pa[4][4]) 
{
    unsigned char i,j,k = 0;
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            pa[j][i] = str[k++];
}

/**
 * 打印4X4的数组
 */
static void printArray(unsigned char a[4][4]) 
{
    unsigned char i,j;
	for(i = 0; i < 4; i++)
	{
        for(j = 0; j < 4; j++)
            printf("a[%d][%d] = 0x%2.2x ", i, j, a[i][j]);
        printf("\n");
    }
    printf("\n");
}

/**
 * 打印字符串的ASSCI，
 * 以十六进制显示。
 */
static void printASSCI(unsigned char *str, unsigned int len) 
{
    unsigned int i;
    for(i = 0; i < len; i++)
        printf("0x%2.2x ", str[i]);
    printf("\n");
}

/**
 * 把连续的4个字符合并成一个4字节的整型
 */
static unsigned long getWordFromStr(unsigned char *str) 
{
    unsigned char i;
	unsigned long value;
	for(i=0;i<4;i++)
		value=((value<<8)|str[i]);
    return value;
}

/**
 * 把一个4字节的数的第一、二、三、四个字节取出，
 * 入进一个4个元素的整型数组里面。
 */
static void splitIntToArray(unsigned long num, unsigned char array[4]) 
{
    unsigned char i;
	for(i=0;i<4;i++)
		array[i]=((num>>(8*(3-i)))&0x000000ff);
}

/**
 * 将数组中的元素循环左移step位
 */
static void leftLoop4int(unsigned char array[4], unsigned char step) 
{
    unsigned char i,index,temp[4];
    for(i = 0; i < 4; i++)
        temp[i] = array[i];//array复制到temp

    index = step % 4;
	for(i = 0; i < 4; i++)
	{
        array[i] = temp[index++];
        index %= 4;
    }
}

/**
 * 把数组中的第一、二、三和四元素分别作为
 * 4字节整型的第一、二、三和四字节，合并成一个4字节整型
 */
static unsigned long mergeArrayToInt(unsigned char array[4]) 
{
    unsigned char i;
	unsigned long value;
	for(i=0;i<4;i++)
		value=((value<<8)|array[i]);
    return value;
}

/**
 * 常量轮值表
 */
static const unsigned long Rcon[10] = { 
    0x01000000, 0x02000000,
    0x04000000, 0x08000000,
    0x10000000, 0x20000000,
    0x40000000, 0x80000000,
    0x1b000000, 0x36000000 };
/**
 * 密钥扩展中的T函数
 */
static unsigned long T(unsigned long num, unsigned char round) 
{
    unsigned char i,numArray[4];
	unsigned long result;
    splitIntToArray(num, numArray);
    leftLoop4int(numArray, 1);//字循环  
    for(i = 0; i < 4; i++)//字节代换
        numArray[i] = getNumFromSBox(numArray[i]);
    result = mergeArrayToInt(numArray);
    return result ^ Rcon[round];
}

//密钥对应的扩展数组
static unsigned char w[44];
/**
 * 打印W数组
 */
static void printW() 
{
    unsigned char i, j;
	for(i = 0, j = 1; i < 44; i++,j++)
	{
        printf("w[%d] = 0x%x ", i, w[i]);
        if(j % 4 == 0)
            printf("\n");
    }
    printf("\n");
}


/**
 * 扩展密钥，结果是把w[44]中的每个元素初始化
 */
static void extendKey(unsigned char *key) 
{
    int i,j;
    for(i = 0; i < 4; i++)
        w[i] = getWordFromStr(key + i * 4);
	for(i = 4, j = 0; i < 44; i++) 
	{
        if( i % 4 == 0) 
		{
            w[i] = w[i - 4] ^ T(w[i - 1], j);
            j++;//下一轮
        }
		else 
            w[i] = w[i - 4] ^ w[i - 1];
    }
}

/**
 * 轮密钥加
 */
static void addRoundKey(unsigned char array[4][4], unsigned char round) 
{
    unsigned char i,j,warray[4];
	for(i = 0; i < 4; i++) 
	{
        splitIntToArray(w[ round * 4 + i], warray);
        for(j = 0; j < 4; j++) 
		{
            array[j][i] = array[j][i] ^ warray[j];
        }
    }
}

/**
 * 字节代换
 */
static void subBytes(unsigned char array[4][4])
{
    unsigned char i,j;
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            array[i][j] = getNumFromSBox(array[i][j]);
}

/**
 * 行移位
 */
static void shiftRows(unsigned char array[4][4]) 
{
    unsigned char rowTwo[4], rowThree[4], rowFour[4];
    unsigned char i;
	for(i = 0; i < 4; i++) 
	{
        rowTwo[i] = array[1][i];
        rowThree[i] = array[2][i];
        rowFour[i] = array[3][i];
    }
    leftLoop4int(rowTwo, 1);
    leftLoop4int(rowThree, 2);
    leftLoop4int(rowFour, 3);
	for(i = 0; i < 4; i++) 
	{
        array[1][i] = rowTwo[i];
        array[2][i] = rowThree[i];
        array[3][i] = rowFour[i];
    }
}

/**
 * 列混合要用到的矩阵
 */
static const unsigned char colM[4][4] = { 
	2, 3, 1, 1,
    1, 2, 3, 1,
    1, 1, 2, 3,
    3, 1, 1, 2 };

/**
 * 在有限域 GF(2^8) 上实现乘以 2 的运算。
 * 有限域 GF(2^8) 上的乘法运算基于多项式乘法，并且结果要对一个特定的不可约多项式（这里是 x^8 + x^4 + x^3 + x + 1，用十六进制表示为 0x1b）取模。
 *
 * @param s 要进行乘法运算的字节
 * @return 乘法运算的结果
 */
static unsigned char GFMul2(unsigned char s) 
{
    // 将输入字节 s 左移 1 位，相当于乘以 2
    unsigned char result = s << 1;
    // 检查 s 的最高位（第 7 位）是否为 1
    if (s & 0x80)
    {
        // 如果最高位为 1，说明左移后会超出 8 位，需要对不可约多项式 0x1b 取模
        result ^= 0x1b;
    }
    return result;
}

/**
 * 在有限域 GF(2^8) 上实现乘以 3 的运算。
 * 由于 3 在二进制中是 11，所以乘以 3 可以表示为乘以 (2 + 1)，即 GFMul2(s) + s，在 GF(2^8) 中加法就是异或运算。
 *
 * @param s 要进行乘法运算的字节
 * @return 乘法运算的结果
 */
static unsigned char GFMul3(unsigned char s)
{
    // 利用 GFMul2 函数实现乘以 3 的运算
    return GFMul2(s) ^ s;
}

/**
 * 在有限域 GF(2^8) 上实现乘以 4 的运算。
 * 因为 4 等于 2 * 2，所以通过两次调用 GFMul2 函数实现乘以 4 的运算。
 *
 * @param s 要进行乘法运算的字节
 * @return 乘法运算的结果
 */
static unsigned char GFMul4(unsigned char s)
{
    // 先对 s 乘以 2，再对结果乘以 2
    return GFMul2(GFMul2(s));
}

/**
 * 在有限域 GF(2^8) 上实现乘以 8 的运算。
 * 由于 8 等于 2 * 2 * 2，所以通过多次调用 GFMul2 函数实现乘以 8 的运算。
 *
 * @param s 要进行乘法运算的字节
 * @return 乘法运算的结果
 */
static unsigned char GFMul8(unsigned char s)
{
    // 先对 s 乘以 4（调用 GFMul4 函数），再对结果乘以 2
    return GFMul2(GFMul4(s));
}

/**
 * 在有限域 GF(2^8) 上实现乘以 9 的运算。
 * 9 可以表示为 8 + 1，所以乘以 9 可以表示为乘以 8 再加上 1，在 GF(2^8) 中加法就是异或运算。
 *
 * @param s 要进行乘法运算的字节
 * @return 乘法运算的结果
 */
static unsigned char GFMul9(unsigned char s)
{
    // 利用 GFMul8 函数实现乘以 8 的运算，然后与 s 进行异或运算
    return GFMul8(s) ^ s;
}

/**
 * 在有限域 GF(2^8) 上实现乘以 11 的运算。
 * 11 可以表示为 9 + 2，所以乘以 11 可以表示为乘以 9 再加上 2，在 GF(2^8) 中加法就是异或运算。
 *
 * @param s 要进行乘法运算的字节
 * @return 乘法运算的结果
 */
static unsigned char GFMul11(unsigned char s)
{
    // 利用 GFMul9 和 GFMul2 函数实现乘以 11 的运算
    return GFMul9(s) ^ GFMul2(s);
}

/**
 * 在有限域 GF(2^8) 上实现乘以 12 的运算。
 * 12 可以表示为 8 + 4，所以乘以 12 可以表示为乘以 8 再加上 4，在 GF(2^8) 中加法就是异或运算。
 *
 * @param s 要进行乘法运算的字节
 * @return 乘法运算的结果
 */
static unsigned char GFMul12(unsigned char s)
{
    // 利用 GFMul8 和 GFMul4 函数实现乘以 12 的运算
    return GFMul8(s) ^ GFMul4(s);
}

/**
 * 在有限域 GF(2^8) 上实现乘以 13 的运算。
 * 13 可以表示为 12 + 1，所以乘以 13 可以表示为乘以 12 再加上 1，在 GF(2^8) 中加法就是异或运算。
 *
 * @param s 要进行乘法运算的字节
 * @return 乘法运算的结果
 */
static unsigned char GFMul13(unsigned char s)
{
    // 利用 GFMul12 函数实现乘以 12 的运算，然后与 s 进行异或运算
    return GFMul12(s) ^ s;
}

/**
 * 在有限域 GF(2^8) 上实现乘以 14 的运算。
 * 14 可以表示为 12 + 2，所以乘以 14 可以表示为乘以 12 再加上 2，在 GF(2^8) 中加法就是异或运算。
 *
 * @param s 要进行乘法运算的字节
 * @return 乘法运算的结果
 */
static unsigned char GFMul14(unsigned char s)
{
    // 利用 GFMul12 和 GFMul2 函数实现乘以 14 的运算
    return GFMul12(s) ^ GFMul2(s);
}

/**
 * GF上的二元运算
 */
static unsigned char GFMul(unsigned char n, unsigned char s) 
{
    unsigned char result;

    if(n == 1)
        result = s;
    else if(n == 2)
        result = GFMul2(s);
    else if(n == 3)
        result = GFMul3(s);
    else if(n == 0x9)
        result = GFMul9(s);
    else if(n == 0xb)//11
        result = GFMul11(s);
    else if(n == 0xd)//13
        result = GFMul13(s);
    else if(n == 0xe)//14
        result = GFMul14(s);
    return result;
}
/**
 * 列混合
 */
static void mixColumns(unsigned char array[4][4]) 
{
    unsigned char tempArray[4][4];
    unsigned char i,j;
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            tempArray[i][j] = array[i][j];
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
		{
            array[i][j] = GFMul(colM[i][0],tempArray[0][j]) ^ GFMul(colM[i][1],tempArray[1][j])
                ^ GFMul(colM[i][2],tempArray[2][j]) ^ GFMul(colM[i][3], tempArray[3][j]);
        }
}
/**
 * 把4X4数组转回字符串
 */
static void convertArrayToStr(unsigned char array[4][4], unsigned char *str) 
{
    unsigned char i,j;
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            *str++ = array[j][i];
}
/**
 * 检查密钥长度
 */
static unsigned char checkKeyLen(unsigned int len) 
{
    if(len == 16)
        return 1;
    else
        return 0;
}


/**
 * 参数 p: 明文的字符串数组。
 * 参数 plen: 明文的长度。
 * 参数 key: 密钥的字符串数组。
 */
void aes(unsigned char *p, unsigned long plen, unsigned char *key)
{

    unsigned char keylen = strlen(key);
    unsigned char pArray[4][4];//status array
    unsigned char k,i;
	if(plen == 0 || plen % 16 != 0) 
	{
        printf("明文字符长度必须为16的倍数！\n");
        exit(0);
    }
	if(!checkKeyLen(keylen)) 
	{
        printf("密钥字符长度错误！长度必须为16。当前长度为%d\n",keylen);
        exit(0);
    }
    extendKey(key);//扩展密钥
	for(k = 0; k < plen; k += 16) 
	{
        convertToIntArray(p + k, pArray);
        addRoundKey(pArray, 0);//一开始的轮密钥加
        for(i = 1; i < 10; i++)//1-9轮
		{
            subBytes(pArray);//字节代换
            shiftRows(pArray);//行移位
            mixColumns(pArray);//列混合
            addRoundKey(pArray, i);//轮密钥加
        }
		//第10轮（无列混合）
        subBytes(pArray);//字节代换
        shiftRows(pArray);//行移位
        addRoundKey(pArray, 10);//轮密钥加
        convertArrayToStr(pArray, p + k);
    }
}
/**
 * 根据索引从逆S盒中获取值
 */
static unsigned char getNumFromS1Box(unsigned char index) 
{
    return S2[index>>4][index&0x0f];
}
/**
 * 逆字节变换
 */
static void deSubBytes(unsigned char array[4][4]) 
{
    unsigned char i,j;
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            array[i][j] = getNumFromS1Box(array[i][j]);
}
/**
 * 将一个包含 4 个元素的数组循环右移指定的步数。
 *
 * @param array 要进行循环右移操作的数组，该数组包含 4 个无符号字符元素。
 * @param step 循环右移的步数。
 */
static void rightLoop4int(unsigned char array[4], unsigned char step) 
{
    // 创建一个临时数组 temp，用于存储原数组 array 的内容
    unsigned char temp[4];
    // 定义两个有符号字符型变量 i 和 index，用于循环计数和索引
    signed char i;
    signed char index;

    // 将原数组 array 的内容复制到临时数组 temp 中
    for (i = 0; i < 4; i++)
        temp[i] = array[i];

    // 计算实际需要右移的步数，确保步数在 0 到 3 之间
    index = step % 4;
    // 计算从临时数组中取元素的起始索引，以实现循环右移
    index = 3 - index;

    // 从数组的最后一个元素开始，按照循环右移的规则，将临时数组中的元素赋值回原数组
    for (i = 3; i >= 0; i--)
    {
        // 将临时数组中指定索引位置的元素赋值给原数组的当前位置
        array[i] = temp[index];
        // 索引减 1，指向下一个要取的元素
        index--;
        // 如果索引小于 0，说明已经到达临时数组的开头，将索引重置为 3，以实现循环
        index = (index == -1) ? 3 : index;
    }
}

/**
 * 逆行移位
 */
 /**
  * 对一个 4x4 的数组执行逆行移位操作，这是 AES 解密过程中的一部分。
  * 在 AES 加密过程中，行移位操作是将矩阵的每一行按照特定的规则进行循环左移。
  * 而逆行移位则是加密过程中行移位的逆操作，即对相应的行进行循环右移。
  *
  * @param array 要进行逆行移位操作的 4x4 无符号字符型数组。
  */
static void deShiftRows(unsigned char array[4][4])
{
    // 定义三个数组，分别用于存储原数组的第二行、第三行和第四行
    unsigned char rowTwo[4], rowThree[4], rowFour[4];
    unsigned char i;

    // 提取原数组的第二行、第三行和第四行数据
    for (i = 0; i < 4; i++)
    {
        rowTwo[i] = array[1][i];
        rowThree[i] = array[2][i];
        rowFour[i] = array[3][i];
    }

    // 对第二行数据进行循环右移 1 位
    rightLoop4int(rowTwo, 1);
    // 对第三行数据进行循环右移 2 位
    rightLoop4int(rowThree, 2);
    // 对第四行数据进行循环右移 3 位
    rightLoop4int(rowFour, 3);

    // 将经过循环右移后的行数据重新放回原数组的对应行
    for (i = 0; i < 4; i++)
    {
        array[1][i] = rowTwo[i];
        array[2][i] = rowThree[i];
        array[3][i] = rowFour[i];
    }
}
/**
 * 逆列混合用到的矩阵
 */
static const unsigned char deColM[4][4] = { 
    0xe, 0xb, 0xd, 0x9,
    0x9, 0xe, 0xb, 0xd,
    0xd, 0x9, 0xe, 0xb,
    0xb, 0xd, 0x9, 0xe };

/**
 * 逆列混合
 */
 /**
  * 对一个 4x4 的数组执行逆列混合操作，这是 AES 解密过程的一部分。
  * 在 AES 加密过程中，列混合操作通过特定的矩阵乘法对列数据进行变换。
  * 逆列混合操作则是使用逆矩阵来恢复原始的列数据。
  *
  * @param array 要进行逆列混合操作的 4x4 无符号字符型数组。
  */
static void deMixColumns(unsigned char array[4][4])
{
    // 创建一个临时数组，用于存储原数组的内容，以便在计算过程中不影响原数据
    unsigned char tempArray[4][4];
    unsigned char i, j;

    // 将原数组的内容复制到临时数组中
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            tempArray[i][j] = array[i][j];

    // 进行逆列混合计算，通过逆列混合矩阵 deColM 对原数组的每一个元素进行计算
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            // 根据逆列混合矩阵和临时数组中的数据，通过有限域乘法 GFMul 和异或操作计算新的元素值
            // 这里通过逆矩阵的系数与临时数组中对应列的元素进行乘法和异或运算，来恢复原始列数据
            array[i][j] = GFMul(deColM[i][0], tempArray[0][j]) ^ GFMul(deColM[i][1], tempArray[1][j])
                ^ GFMul(deColM[i][2], tempArray[2][j]) ^ GFMul(deColM[i][3], tempArray[3][j]);
        }
}

/**
 * 把两个4X4数组进行异或
 */
static void addRoundTowArray(unsigned char aArray[4][4],unsigned char bArray[4][4]) 
{
    unsigned char i,j;
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            aArray[i][j] = aArray[i][j] ^ bArray[i][j];
}
/**
 * 从4个32位的密钥字中获得4X4数组，
 * 用于进行逆列混合
 */
static void getArrayFrom4W(unsigned char i, unsigned char array[4][4]) 
{
    unsigned char index,j;
    unsigned char colOne[4], colTwo[4], colThree[4], colFour[4];
    index = i * 4;
    splitIntToArray(w[index], colOne);
    splitIntToArray(w[index + 1], colTwo);
    splitIntToArray(w[index + 2], colThree);
    splitIntToArray(w[index + 3], colFour);
	for(j = 0; j < 4; j++)
	{
        array[j][0] = colOne[j];
        array[j][1] = colTwo[j];
        array[j][2] = colThree[j];
        array[j][3] = colFour[j];
    }
}

/**
 * 参数 c: 密文的字符串数组。
 * 参数 clen: 密文的长度。
 * 参数 key: 密钥的字符串数组。
 */
void deAes(unsigned char *c, unsigned long clen, unsigned char *key) 
{
    unsigned char cArray[4][4];
    unsigned char keylen,k;
	
    keylen = strlen(key);
	if(clen == 0 || clen % 16 != 0) 
	{
        printf("密文字符长度必须为16的倍数！现在的长度为%d\n",clen);
        exit(0);
    }
	if(!checkKeyLen(keylen)) 
	{
        printf("密钥字符长度错误！长度必须为16、24和32。当前长度为%d\n",keylen);
        exit(0);
	}
    extendKey(key);//扩展密钥
	for(k = 0; k < clen; k += 16) 
	{
        unsigned char i;
        unsigned char wArray[4][4];
        convertToIntArray(c + k, cArray);
        addRoundKey(cArray, 10);
        for(i = 9; i >= 1; i--) 
		{
            deSubBytes(cArray);
            deShiftRows(cArray);
            deMixColumns(cArray);
            getArrayFrom4W(i, wArray);
            deMixColumns(wArray);
            addRoundTowArray(cArray, wArray);
        }
        deSubBytes(cArray);
        deShiftRows(cArray);
        addRoundKey(cArray, 0);
        convertArrayToStr(cArray, c + k);
    }
}
