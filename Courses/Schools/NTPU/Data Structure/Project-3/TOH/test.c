#include <stdio.h>

int main()
{
    unsigned i, num;

    scanf("%d", &num);

    for ( i = 1; i <= num; i++ )
    {
        printf("\ni = %d, ( i & ( i - 1 ) ) = %d, ( ( i | ( i - 1 ) ) + 1 ) = %d\n", i, ( i & ( i - 1 ) ), ( ( i | ( i - 1 ) ) + 1 ) );
    }

    printf("\n\n");
    system("pause");
}