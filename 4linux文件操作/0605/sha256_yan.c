// sha256 + 盐
#include <stdio.h>
#include <string.h>
#include <string.h>

#include <openssl/sha.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
// 固定盐长
#define YAN_LEN 16

//字符串进行sha256加密
void sha256(char *ch);
// 字符串sha256 + 盐加密
void sha256_yan(char *ch);

// 文本文件sha256加密
void sha256_file(char *name);
// 文本文件sha256 + 盐加密                  把盐加在文件内容前
void sha256_yan_file(char *name);

int main()
{
    sha256("a");
    sha256_yan("a");
    sha256_file("a.txt");
    sha256_yan_file("a.txt");
    return 0;
}
void sha256(char *ch)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    // 上下文
    SHA256_CTX ctx;
    // 初始化
    SHA256_Init(&ctx);
    // 更新
    SHA256_Update(&ctx, ch, strlen(ch));
    // 生成
    SHA256_Final(hash, &ctx);
    // 打印
    printf("SHA256：");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");
}
void sha256_yan(char *ch)
{
    unsigned char yan[YAN_LEN];
    int a = RAND_bytes(yan, YAN_LEN);
    if (a != 1)
    {
        perror("随机盐生成失败\n");
        return;
    }
    char *b = malloc(YAN_LEN + strlen(ch) + 1);
    if (b == NULL)
    {
        perror("内存申请失败\n");
        return;
    }
    memcpy(b, yan, YAN_LEN);
    memcpy(b + YAN_LEN, ch, strlen(ch));
    sha256(b);
    free(b);
}
void sha256_file(char *name)
{
    FILE *in = fopen(name, "r");
    if (in == NULL)
    {
        perror("无法打开文件\n");
        return;
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);

    int n;
    char buf[4096];
    while ((n = fread(buf, 1, sizeof(buf), in)) > 0)
    {
        SHA256_Update(&ctx, buf, n);
    }
    SHA256_Final(hash, &ctx);

    fclose(in);
    printf("SHA256：");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");
}
void sha256_yan_file(char *name)
{
    unsigned char yan[YAN_LEN];
    int a = RAND_bytes(yan, YAN_LEN);
    if (a != 1)
    {
        perror("随机盐生成失败\n");
        return;
    }

    FILE *in = fopen(name, "r");
    if (in == NULL)
    {
        perror("无法打开文件\n");
        return;
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, yan, YAN_LEN);

    int n;
    char buf[4096];
    while ((n = fread(buf, 1, sizeof(buf), in)) > 0)
    {
        SHA256_Update(&ctx, buf, n);
    }
    SHA256_Final(hash, &ctx);

    fclose(in);
    printf("SHA256：");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");
}
