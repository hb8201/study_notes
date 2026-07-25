// my.h
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// 声明
// 参数：形式参数
void printf_array(int x[], int len);

// 1.c调用
void selection_sort(int b[], int x);

// 2.c调用
float pay_taxes(float a);

// 3.c调用
void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

// 4.c调用
void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

// 5.c调用
void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

// 6.c调用
float polynomial(float x);

// 7.c调用
int power(int x, int n);

//8.c调用
int roll_dice(void);
bool play_game(void);