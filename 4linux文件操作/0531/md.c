// md.c
// 摘要算法         -lcrypto
#include <stdio.h>
#include <string.h>

#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/evp.h>

// // 32位
// // 已被破解，不能对密码进行加密，推荐使用SHA256
// // 可以用于文件验证、查重（快）
// void to_md5(char *str)
// {
//     // 16
//     unsigned char hash[MD5_DIGEST_LENGTH];
//     // 上下文 context - 环境/场景
//     MD5_CTX ctx;
//     // 初始化上下文
//     MD5_Init(&ctx);
//     // 更新（多次，分片执行）上下文
//     MD5_Update(&ctx, str, strlen(str));
//     // 生成最终的哈希值（摘要信息）
//     MD5_Final(hash, &ctx);

//     // 转十六进制 -> 32（位）
//     printf("MD5:\t");
//     for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
//     {
//         printf("%02x",hash[i]);
//     }
//     printf("\n");
// }

// void to_sha256(char *str)
// {
//     // 32 -> 64
//     unsigned char hash[SHA256_DIGEST_LENGTH];

//     SHA256_CTX ctx;
//     SHA256_Init(&ctx);                          // 初始化
//     SHA256_Update(&ctx, str, strlen(str));      // 更新
//     SHA256_Final(hash, &ctx);                   // 生成
//     //
//     printf("SHA256:\t");
//     for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
//     {
//         printf("%02x", hash[i]);
//     }
//     printf("\n");
// }

// void file_sha1(char *filename)
// {
//     FILE *fp = fopen(filename, "rb");
//     if (fp == NULL)
//     {
//         perror("无法打开文件\n");
//         return;
//     }
//     unsigned char hash[SHA_DIGEST_LENGTH];
//     // 系统文件块大小
//     char buf[4096];
//     size_t n;
//     SHA_CTX ctx;
//     SHA1_Init(&ctx);
//     while ((n = fread(buf, 1, sizeof(buf), fp)) > 0)
//     {
//         SHA1_Update(&ctx, buf, n);
//     }
//     SHA1_Final(hash, &ctx);
//     fclose(fp);

//     printf("SHA128:\t");
//     for (int i = 0; i < SHA_DIGEST_LENGTH; i++)
//     {
//         printf("%02x", hash[i]);
//     }
//     printf("\n");
// }

void evp_to_md5(char *str)
{
    // MD5_CTX ctx;
    // MD5_Init(&ctx);
    // MD5_Update(&ctx, str, strlen(str));
    // MD5_Final(hash, &ctx);
    unsigned char hash[SHA256_DIGEST_LENGTH];
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    // 上下文   算法    引擎
    EVP_DigestInit_ex(ctx, EVP_sha256(), NULL);      // 中间参数 EVP_md5 EVP_sha1 EVP_sha256
    EVP_DigestUpdate(ctx, str, strlen(str));
    int len;
    EVP_DigestFinal_ex(ctx, hash, &len);
    EVP_MD_CTX_free(ctx);                           // 释放空间
    printf("MD5:\t");
    for (int i = 0; i < len; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main()
{
    char *str = "hello openSSL";
    // to_md5(str);
    // to_sha256(str);
    // file_sha1("md");

    evp_to_md5(str);


    return 0;
}
