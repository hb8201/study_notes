/*  切分文件，bit torrent 协议，比特湍流 p2p
    512k
    ./splice xxx.pdf
    切成多个文件


meta.info   存储每个文件哈希值 一行一个，最后一行为整体的哈希值
*/
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/evp.h>
#define ZIJIE 1024

int zijie(char *name);
void sha256(char *name, int len);
void qiefen(char *name);

int main()
{
    qiefen("md.c");

    return 0;
}
// 获得文件的字节数
int zijie(char *name)
{
    FILE *fp = fopen(name, "r");
    if (fp == NULL)
    {
        perror("无法打开文件\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    int a = ftell(fp);
    fclose(fp);
    return a;
}
// 将文件编码成哈希值
void sha256(char *buf, int len)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_sha256(), NULL);
    EVP_DigestUpdate(ctx, buf, len);        // 因为文件里可能存在 '\0' 所以不考虑用strlen(buf)
    unsigned int len1;
    EVP_DigestFinal_ex(ctx, hash, &len1);
    EVP_MD_CTX_free(ctx);
    FILE *out = fopen("meta.info", "a");
    if (out == NULL)
    {
        perror("无法打开文件\n");
        return;
    }
    for (int i = 0; i < len1; i++)
    {
        fprintf(out, "%02x", hash[i]);
    }
    fprintf(out, "\n");
    fclose(out);
}
// 切分文件
void qiefen(char *name)
{
    FILE *fp = fopen(name, "rb");
    if (fp == NULL)
    {
        perror("无法打开文件\n");
        return;
    }
    int a = zijie(name);
    char ch1[20], ch2[20];
    int n;
    for (int i = 1; i <= (a / ZIJIE) + 1; i++)
    {
        char buf[ZIJIE];
        sprintf(ch1, "out%d", i);
        sprintf(ch2, "%d.txt", i);
        FILE *ch1 = fopen(ch2, "w");
            if (ch1 == NULL)
        {
            perror("无法打开文件\n");
            return;
        }
        n = fread(buf, 1, sizeof(buf), fp);
        fwrite(buf, 1, n, ch1);
        fclose(ch1);
        sha256(buf, n);
    }
    fclose(fp);
}
