#include <stdio.h>

int main()
{
    unsigned int N, k1, k2;

    while (scanf("%d %d %d", &N, &k1, &k2) != EOF)
    {
        unsigned int d;

        if (k1 >= k2)
        {
            d = k1 - k2;
        }
        else
        {
            d = k2 - k1;
        }

        if (d < 2)
        {
            printf("%s\n", ":)");
        }
        else
        {
            int bottle = 0, e = N;

            while (e >= (d-1))
            {
                if (e == (d-1))
                {
                    bottle += 1;
                    e = 0;
                }
                else
                {
                    int b0 = e / d;

                    e = b0 + (e % d);
                    bottle += b0;
                }
            }

            printf("%d\n", bottle + N);
        }
    }
}