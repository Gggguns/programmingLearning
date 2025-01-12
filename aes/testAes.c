#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 假设 aes.h 中包含了所有相关函数的声明
#include "aes.h"

// 测试函数
int main() {
    // 待加密的明文
    //const char *original_plaintext = "Hello, AES!";

    // 存储用户输入的明文
    char original_plaintext[1024];
    printf("请输入要加密的明文: ");
    if (fgets(original_plaintext, sizeof(original_plaintext), stdin) == NULL) {
        printf("读取输入失败\n");
        return 1;
    }
    // 移除换行符
    size_t original_len = strlen(original_plaintext);
    if (original_plaintext[original_len - 1] == '\n') {
        original_plaintext[original_len - 1] = '\0';
    }


    // 计算填充后的长度
    size_t plaintext_len = original_len;
    while (plaintext_len % 16!= 0) {
        plaintext_len++;
    }

    // 分配内存用于存储填充后的明文
    unsigned char *plaintext = (unsigned char*)malloc(plaintext_len);
    if (plaintext == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    // 复制原始明文到新分配的内存
    memcpy(plaintext, original_plaintext, original_len);
    // 填充 0
    for (size_t i = original_len; i < plaintext_len; i++) {
        plaintext[i] = 0;
    }

    // 密钥，长度必须为 16
    unsigned char key[] = "This is a 16 key";

    // 动态分配内存用于存储加密后的密文
    unsigned char *ciphertext = (unsigned char*)malloc(plaintext_len);
    if (ciphertext == NULL) {
        printf("内存分配失败\n");
        free(plaintext);
        return 1;
    }
    memcpy(ciphertext, plaintext, plaintext_len);

    // 调用 aes 函数进行加密
    aes(ciphertext, plaintext_len, key);

    // 输出加密后的密文
    printf("加密后的密文: ");
    for (size_t i = 0; i < plaintext_len; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\n");

    // 动态分配内存用于存储解密后的明文
    unsigned char *decrypted_text = (unsigned char*)malloc(plaintext_len);
    if (decrypted_text == NULL) {
        printf("内存分配失败\n");
        free(ciphertext);
        free(plaintext);
        return 1;
    }
    memcpy(decrypted_text, ciphertext, plaintext_len);

    // 调用 deAes 函数进行解密
    deAes(decrypted_text, plaintext_len, key);

    // 输出解密后的明文
    printf("解密后的明文: ");
    for (size_t i = 0; i < plaintext_len; i++) {
        if (decrypted_text[i]!= 0) {
            printf("%c", decrypted_text[i]);
        }
    }
    printf("\n");

    // 释放动态分配的内存
    free(plaintext);
    free(ciphertext);
    free(decrypted_text);

    return 0;
}