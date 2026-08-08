// my.c
// MySQL C API
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mysql/mysql.h>

#define HOST "127.0.0.1"
#define USER "tom"
#define PASSWD "123456"
#define DB "hr"
#define PORT 3306


int main(int argc, char const *argv[])
{
    // 初始化数据库连接
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL)
    {
        perror("初始化失败\n");
        return -1;
    }

    // 建立连接
    if (mysql_real_connect(conn, HOST, USER, PASSWD, DB, PORT, NULL, 0) == NULL)
    {
        fprintf(stderr, "连接失败：%s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;
    }
    printf("连接成功！\n");

    // 执行 DML
    char *sql = "SELECT id, name, city FROM dept";
    // char *sql = "INSERT INTO dept VALUES(NULL, 'Test', 'changsha')";
    //0为成功，非0错误
    if (mysql_real_query(conn, sql, strlen(sql)) != 0)
    {
        fprintf(stderr, "执行查询：%s\n", mysql_error(conn));
        mysql_close(conn);
        return -1;
    }
    // 获取执行查询的结果集
    MYSQL_RES *res = mysql_store_result(conn);
    printf("行数：%ld，列数：%d\n", res->row_count, res->field_count);


    // 列，字段
    MYSQL_FIELD *field;
    // 遍历字段（获得一个字段）
    while ((field = mysql_fetch_field(res)) != NULL)
    {
        printf("%s, %d, %ld\n", field->name, field->type, field->length);
    }

    // 获得所有字段构成的数组
    field = mysql_fetch_fields(res);
    for (int i = 0; i < res->field_count; i++)
    {
        printf("%s\t", field[i].name);
    }
    printf("\n");


    // 行，记录（字符串数组）
    MYSQL_ROW row;
    // int cols = mysql_field_count(conn);
    int cols = res->field_count;
    while ((row = mysql_fetch_row(res)) != NULL)
    {
        // 遍历每个列
        for(int i = 0; i < res->field_count; i++)
        {
            printf("%s\t", row[i]);
        }
        printf("\n");
    }
    
    
    mysql_free_result(res);

    mysql_close(conn);


    return 0;
}
