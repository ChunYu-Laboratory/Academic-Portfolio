#include <stdio.h>

typedef struct
{
    char msg[8];
    unsigned next;
} record;

int main()
{
    FILE* fp;
    int f;
    record message;

    fp = fopen( "testdata1.in", "rb" );

    fread( &f, sizeof(int), 1, fp );

    fseek( fp, sizeof(int)+(f-1)*sizeof(record), SEEK_SET );

    while ( fread( &message, sizeof(record), 1, fp ) )
    {
        printf( "%s\n", message.msg );

        if ( message.next == 0 )
        {
            break;
        }

        fseek( fp, sizeof(int)+(message.next-1)*sizeof(record), SEEK_SET );
    }

    fclose( fp );
}