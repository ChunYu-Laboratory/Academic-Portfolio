#include <stdio.h>

int main()
{
    int n, i, k;
    char filename[257], new_filename[257], substitution[257];
    char *start, *end, *loc, *extension_loc;

    scanf( "%d\n", &n );

    for ( ; n > 0; n-- )
    {
        gets( filename );
        gets( substitution );

        end = filename;

        while ( *end != '\0' )
        {
            end++;
        }

        start = end;

        while ( *start != '.' )
        {
            if ( start == filename )
            {
                break;
            }
            start--;
        }

        if ( start != filename )
        {
            extension_loc = start;
        }
        else
        {
            extension_loc = NULL;
        }

        if ( extension_loc != NULL )
        {
            start = extension_loc;
            end = extension_loc;
        }
        else
        {
            start = end;
        }

        while ( ( *start != '\\' ) && ( *start != ':' ) )
        {
            if ( start == filename )
            {
                break;
            }
            start--;
        }

        if ( start != filename )
        {
            start++;
        }

        i = 0;

        for ( k = start - filename; i < k; i++ )
        {
            new_filename[i] = filename[i];
        }

        loc = substitution;

        while ( *loc != '\0' )
        {
            new_filename[i] = *loc;

            loc++;
            i++;
        }

        if ( extension_loc != NULL )
        {
            while ( *extension_loc != '\0' )
            {
                new_filename[i] = *extension_loc;

                extension_loc++;
                i++;
            }
        }

        new_filename[i] = '\0';

        puts( new_filename );
    }
}