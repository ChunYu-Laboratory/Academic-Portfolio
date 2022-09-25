#include <stdio.h>

int main()
{
    unsigned int y;

    while (scanf("%d", &y) != EOF)
    {
        if ((y % 4) == 0)
        {
            if ((y % 400) == 0)
            {
                printf("%s\n", "leap");
            }
            else
            {
                if ((y % 100) == 0)
                {
                    printf("%s\n", "nonleap");
                }
                else
                {
                    printf("%s\n", "leap");
                }
            }
        }
        else
        {
            printf("%s\n", "nonleap");
        }
    }
}