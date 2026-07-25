#include <stdio.h>

int main()
{
    int m, d, y;
    int m1 = 99, d1 = 99, y1 = 9999;

    do
    {
        printf("Enter a date （mm/dd/yy）: ");
        scanf("%d/%d/%d", &m, &d, &y);

        if (y == 00 && m == 00 & d == 0)
            break;

        if (y < y1)
        {
            y1 = y;
            m1 = m;
            d1 = d;
        }
        else if (y > y1)
        {
        }
        else
        {
            if (m < m1)
            {
                y1 = y;
                m1 = m;
                d1 = d;
            }
            else if (m > m1)
            {
            }
            else
            {
                if (d < d1)
                {
                    y1 = y;
                    m1 = m;
                    d1 = d;
                }
            }
        }

    } while (1);

    printf("%d/%d/%02d is the earliest date\n", m1, d1, y1);

    return 0;
}