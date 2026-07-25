// wchar.c
// 宽字符
#include <stdio.h>
#include <wchar.h>
// i18n 国际化
// l10n 本地化
#include <locale.h>

int main()
{
    // 语言_地区.编码方式
    setlocale(LC_ALL, "zh_CN.UTF-8");
    // wide 宽字符：多字节字符
    wchar_t ch = L'💩';
    wprintf(L"字符=%lc, 编码值=%#x\n", ch, ch);
    return 0;
}