// my.c
// 函数定义
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>


void printf_array(int x[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d,", x[i]);
    }
    printf("\n");
}

// 1.c调用
void selection_sort(int b[], int x)
{
    int y, z = 0;

    if (x > 1)
    {
        for (int i = 0; i < x; i++)
        {
            if (b[i] > z)
            {
                z = b[i];
                y = i;
            }
        }

        for (int i = y; i < x - 1; i++)
            b[i] = b[i + 1];

        b[x - 1] = z;
        selection_sort(b, x - 1);
    }
}

// 2.c调用
float pay_taxes(float a)
{
    float b;

    if (a < 750)
        b = a * 0.01;
    else if (a < 2250)
        b = 7.50 + (a - 750) * 0.02;
    else if (a < 3750)
        b = 37.50 + (a - 2250) * 0.03;
    else if (a < 5250)
        b = 82.50 + (a - 3750) * 0.04;
    else if (a < 7000)
        b = 142.50 + (a - 5250) * 0.05;
    else
        b = 230.00 + (a - 7000) * 0.06;

    return b;
}

// 3.c调用
void generate_random_walk(char walk[10][10])
{
    int f, n = 26;
    int a1 = 0, a2 = 0;
    int z[4] = {0};

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            walk[i][j] = '.';
    }

    walk[a1][a2] = 'A';
    srand((unsigned)time(NULL)); // 用当前时间戳设置种子

    while (n > 1)
    {
        f = rand() % 4; // a + rand() % (b - a + 1) 生成随机数 a~b

        if (z[0] == 1 && z[1] == 1 && z[2] == 1 && z[3] == 1)
            break;

        switch (f)
        {
        case 0: // 上
        {
            if (a1 - 1 >= 0 && walk[a1 - 1][a2] == '.')
            {
                walk[a1 - 1][a2] = walk[a1][a2] + 1;
                a1--;
                n--;
                z[0] = z[1] = z[2] = z[3] = 0;
                break;
            }
            z[0] = 1;
            break;
        }
        case 1: // 右
        {
            if (a2 + 1 <= 9 && walk[a1][a2 + 1] == '.')
            {
                walk[a1][a2 + 1] = walk[a1][a2] + 1;
                a2++;
                n--;
                z[0] = z[1] = z[2] = z[3] = 0;
                break;
            }
            z[1] = 1;
            break;
        }
        case 2: // 下
        {
            if (a1 + 1 <= 9 && walk[a1 + 1][a2] == '.')
            {
                walk[a1 + 1][a2] = walk[a1][a2] + 1;
                a1++;
                n--;
                z[0] = z[1] = z[2] = z[3] = 0;
                break;
            }
            z[2] = 1;
            break;
        }
        case 3: // 左
        {
            if (a2 - 1 >= 0 && walk[a1][a2 - 1] == '.')
            {
                walk[a1][a2 - 1] = walk[a1][a2] + 1;
                a2--;
                n--;
                z[0] = z[1] = z[2] = z[3] = 0;
                break;
            }
            z[3] = 1;
            break;
        }
        }
    }
}

void print_array(char walk[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            printf("%c ", walk[i][j]);
        printf("\n");
    }
}

// 4.c调用
void read_word(int counts[26])
{
    int i = 0;
    char word[99];
    printf("请输入一个单词：");
    fgets(word, 99, stdin);

    while (1)
    {
        if (word[i] == '\n')
        {
            i = 0;
            break;
        }
        word[i] = tolower(word[i]);
        counts[word[i] - 'a']++;
        i++;
    }
}

bool equal_array(int counts1[26], int counts2[26])
{
    int a = 0;
    int counts[26];

    for (int i = 0; i < 26; i++)
    {
        counts[i] = counts1[i] - counts2[i];
        if (counts[i] != 0)
            a++;
    }

    if (a == 0)
    {
        printf("两个词是变位词\n");
        return true;
    }
    else
    {
        printf("两个词不是变位词\n");
        return false;
    }
}

// 5.c调用
void create_magic_square(int n, int magic_square[n][n])
{
    int x, y, z;
    x = 0;
    y = n / 2;
    z = n * n;
    magic_square[x][y] = 1;

    while (z > 0)
    {
        if (x - 1 < 0)
        {
            int x1, y1;         //下一步位置
            x1 = n - 1;

            if (y + 1 >= n)
                y1 = 0;
            else
                y1 = y + 1;

            if (magic_square[x1][y1] != 0)
            {
                magic_square[x + 1][y] = magic_square[x][y] + 1;
                x++;
                z--;
            }
            else
            {
                magic_square[x1][y1] = magic_square[x][y] + 1;
                x = x1;
                y = y1;
                z--;
            }

        }
        else
        {
            int x1, y1;
            x1 = x - 1;

            if (y + 1 >= n)
                y1 = 0;
            else
                y1 = y + 1;

            if (magic_square[x1][y1] != 0)
            {
                magic_square[x + 1][y] = magic_square[x][y] + 1;
                x++;
                z--;
            }
            else
            {
                magic_square[x1][y1] = magic_square[x][y] + 1;
                x = x1;
                y = y1;
                z--;
            }
        }
    }
}

void print_magic_square(int n, int magic_square[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%3d  ", magic_square[i][j]);
        printf("\n");
    }

}

// 6.c调用
float polynomial(float x)
{
    float y;

    y = 3 * x * x * x * x * x
      + 2 * x * x * x * x
      - 5 * x * x * x
      - 1 * x * x
      + 7 * x
      - 6;

    return y;
}

// 7.c调用
int power(int x, int n)
{
    if (n == 0)
        return 1;

    if (n % 2 != 0)
        return x * power(x, n - 1);
    else
        return power(x, n / 2) * power(x, n / 2);
}

// 8.c调用
int roll_dice(void)
{
    int f1, f2;
    f1 = 1 + rand() % 6; // a + rand() % (b - a + 1) 生成随机数 a~b
    f2 = 1 + rand() % 6;

    printf("You rolled: %d\n", f1 + f2);
    return f1 + f2;
}

bool play_game(void)
{
    int f, F;
    f = roll_dice();
    if (f == 7 || f == 11)
    {
        printf("You win!\n\n");
        return true;
    }
    else if (f == 2 || f == 3 || f == 12)
    {
        printf("You lose!\n\n");
        return false;
    }

    printf("Your point is %d\n", f);
    while (1)
    {
        F = roll_dice();
        if (f == F)
        {
            printf("You win!\n\n");
            return true;
        }
        else if (F == 7)
        {
            printf("You lose!\n\n");
            return false;
        }
    }
}