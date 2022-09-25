#include <stdio.h>

int main()
{
    int cola;

    while (scanf("%d", &cola) == 1)
    {
        int total = cola, k = 3, n = 0;

        while (cola >= k)
        {
            cola -= k;
            cola++;
            total++;
            n++;

            if((n % 10) == 0)
            {
                k++;
            }
        }
        
        if(cola == (k-1))
        {
            printf("%d\n", total + 1);
        }
        else
        {
            printf("%d\n", total);
        }
    }
}