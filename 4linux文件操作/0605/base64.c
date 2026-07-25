// base64.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <openssl/evp.h>
#include <openssl/bio.h>        // basic input output   base的标准输入输出, 类似 FILE
#include <openssl/buffer.h>

// base64编码
char *encode (char *str)
{
    // 过滤器 filter
    BIO *b64 = BIO_new(BIO_f_base64());
    // source 为内存的 bio
    BIO *bio = BIO_new(BIO_s_mem());
    // 给bio加上base64过滤器
    bio = BIO_push(b64, bio);
    // 不换行
    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);

    // 把str写入bio
    BIO_write(bio, str, strlen(str));
    // 刷新缓冲区
    BIO_flush(bio);
    // 内存缓冲区
    BUF_MEM *buf;
    BIO_get_mem_ptr(bio, &buf);

    // 动态分配的堆空间
    char *data = malloc(buf->length + 1);
    memcpy(data, buf->data, buf->length);
    data[buf->length] = '\0';   // data[buf->length] = 0;
    BIO_free_all(bio);

    return data;
}

char *decode(char *data, int *len)
{
    // filter 过滤器， 装饰器模式
    BIO *b64 = BIO_new(BIO_f_base64());

    int input_len = strlen(data);
    printf("%d\n", input_len);

    char *buf = malloc(input_len);
    BIO *bio = BIO_new_mem_buf(data, input_len);
    bio = BIO_push(b64, bio);
    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);

    // base64 传到 BIO 内存缓冲区
    *len = BIO_read(bio, buf, input_len);
    printf("%d\n", *len);
    BIO_free_all(bio);

    return buf;
}

void encode_file(char *in_file, char *out_file)
{
    // 读
    BIO *in = BIO_new_file(in_file, "rb");
    // 写
    BIO *out = BIO_new_file(out_file, "w");

    // 给输出流加过滤器
    BIO *b64 = BIO_new(BIO_f_base64());
    out = BIO_push(b64, out);

    char buf[1024 * 4];
    int n;
    while ((n = BIO_read(in, buf, sizeof(buf))) > 0)
    {
        BIO_write(out, buf, n);
    }
    BIO_flush(out);
    BIO_free_all(in);
    BIO_free_all(out);
    printf("OK\n");
}

void decode_file(char *in_file, char *out_file)
{
    // FILE *fp = fopen(in_file, "r");      类似
    // fread()
    // fwrite()
    // fflush()
    // fclose()
    
    BIO *in = BIO_new_file(in_file, "r");
    BIO *out = BIO_new_file(out_file, "wb");

    BIO *base64 = BIO_new(BIO_f_base64());
    in = BIO_push(base64, in);

    char buf[1024 * 4];
    int n;
    while ((n = BIO_read(in, buf, sizeof(buf))) > 0)
    {
        BIO_write(out, buf, n);
    }
    BIO_flush(out);
    BIO_free_all(in);
    BIO_free_all(out);
    printf("OK\n");
}

int main()
{
    // // 文本编码与解码
    // // hello
    // // aGVsbG8=
    // char *str = "hello";
    // char *base64 = encode(str);
    // printf("%s\n", base64);

    // char *data = "aGVsbG8=";
    // int len = 0;
    // char *text = decode(data, &len);
    // printf("%s\n", text);
    // printf("%.*s\n", len, text);
    // free(text);

    // 文件编码与解码
    // data:image/jpeg;base64,xxxxxxxxxxxxxxxxxx
    encode_file("a.jpeg", "a.txt");

    // png, jpg, jpeg, jif, webp ...
    // 
    decode_file("a.txt", "b.jpeg");

    return 0;
}
