#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000], output[1000];

    while ( gets( input ) )
    {
        int i;
        int len = strlen( input );
        char *loc_ptr1 = input, *loc_ptr2 = output;

        while ( loc_ptr1 < input + len )
        {
            if ( ( *loc_ptr1 == 'M' ) && ( *(loc_ptr1 + 1) == 'y' ) )
            {
                strncpy( loc_ptr2, "Your", 4 );

                loc_ptr1 += 2;
                loc_ptr2 += 4;
            }
            else if ( ( *loc_ptr1 == 'm' ) && ( *(loc_ptr1 + 1) == 'y' ) )
            {
                strncpy( loc_ptr2, "your", 4 );

                loc_ptr1 += 2;
                loc_ptr2 += 4;
            }
            else
            {
                *loc_ptr2 = *loc_ptr1;

                loc_ptr1++;
                loc_ptr2++;
            }
        }

        *loc_ptr2 = '\0';
        
        puts( output );
    }
}