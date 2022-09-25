#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char bool;

typedef struct
{
    bool isupper;
    char *location;
} status;

int compare( const void * , const void * );

int main()
{
    char input[100], output[100];

    while ( gets( input ) )
    {
        int count = 0, i, num;
        int len = strlen( input );
        status replace[100];
        char *loc_ptr = input;
        char *start_ptr, *end_ptr;

        while ( loc_ptr < input + len )
        {
            loc_ptr = strstr( loc_ptr, "My" );

            if ( loc_ptr != NULL )
            {
                replace[count].isupper = 1;
                replace[count].location = loc_ptr;

                loc_ptr += 2;
                count++;
            }
            else
            {
                break;
            }
        }

        loc_ptr = input;

        while ( loc_ptr < input + len )
        {
            loc_ptr = strstr( loc_ptr, "my" );

            if ( loc_ptr != NULL )
            {
                replace[count].isupper = 0;
                replace[count].location = loc_ptr;

                loc_ptr += 2;
                count++;
            }
            else
            {
                break;
            }
        }

        qsort( replace, count, sizeof(status), compare );

        for ( i = 0, start_ptr = input, loc_ptr = output; i < count; i++ )
        {
            end_ptr = replace[i].location;

            num = end_ptr - start_ptr;

            strncpy( loc_ptr, start_ptr, num );

            loc_ptr += num;

            if ( replace[i].isupper )
            {
                strncpy( loc_ptr, "Your", 4 );
            }
            else
            {
                strncpy( loc_ptr, "your", 4 );
            }

            loc_ptr += 4;
            start_ptr += 2;
        }

        strcpy( loc_ptr, start_ptr );

        puts( output );
    }
}

int compare( const void *a, const void *b )
{
    const status *i = (const status*) a;
    const status *j = (const status*) b;

    return i->location < j->location ? -1 : 1;
}