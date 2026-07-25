#include <stdio.h>

int main()
{
    char ch[100];

    printf("Enter phone number: ");
    fgets(ch, 100, stdin);

    for (int i = 0; i < 100; i++)
    {
        if (ch[i] == '\n')
            break;
        
        if ((ch[i] >= 65 && ch[i] <= 90) || (ch[i] >= 'a' && ch[i] <= 'z'))
        {
            switch (ch[i])
            {
            case 'a':
            case 'A':
            case 'b':
            case 'B':
            case 'c':
            case 'C':   ch[i] = '2'; break;
            case 'd':
            case 'D':
            case 'e':
            case 'E':
            case 'f':
            case 'F':   ch[i] = '3'; break;
            case 'g':
            case 'G':
            case 'h':
            case 'H':
            case 'i':
            case 'I':   ch[i] = '4'; break;
            case 'j':
            case 'J':
            case 'k':
            case 'K':
            case 'l':
            case 'L':   ch[i] = '5'; break;
            case 'm':
            case 'M':
            case 'n':
            case 'N':
            case 'o':
            case 'O':   ch[i] = '6'; break;
            case 'p':
            case 'P':
            case 'q':
            case 'Q':
            case 'r':
            case 'R':
            case 's':
            case 'S':   ch[i] = '7'; break;
            case 't':
            case 'T':
            case 'u':
            case 'U':
            case 'v':
            case 'V':   ch[i] = '8'; break;
            case 'w':
            case 'W':
            case 'x':
            case 'X':
            case 'y':
            case 'Y':
            case 'z':
            case 'Z':   ch[i] = '9'; break;
            }
        }
    }

    printf("In number from: %s", ch);

    return 0;
}