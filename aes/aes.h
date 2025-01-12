#ifndef MY_AES_H
#define MY_AES_H

/**
 * 参数 p: 明文的字符串数组。
 * 参数 plen: 明文的长度,长度必须为16的倍数。
 * 参数 key: 密钥的字符串数组。
 */
void aes(unsigned char *p, unsigned long plen, unsigned char *key);

/**
 * 参数 c: 密文的字符串数组。
 * 参数 clen: 密文的长度,长度必须为16的倍数。
 * 参数 key: 密钥的字符串数组。
 */
void deAes(unsigned char *c, unsigned long clen, unsigned char *key);

#endif
