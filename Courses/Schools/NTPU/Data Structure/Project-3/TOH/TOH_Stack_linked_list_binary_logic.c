#include <stdio.h>
#include <stdlib.h>


typedef struct listNode
{
    unsigned data;
    struct listNode *link;
} listNode;


typedef struct
{
    listNode *top;
} stack;


stack createStack();

void push( stack *, unsigned );

unsigned pop( stack * );


int main()
{
    unsigned num_disk;
    unsigned source, destination;
    unsigned i;
    unsigned disk_serial_num;
    unsigned step = 1;
    
    stack pillar0 = createStack();
    stack pillar1 = createStack();
    stack pillar2 = createStack();

    printf( "Please enter the number of disks : " );
    scanf( "%d", &num_disk );

    for ( i = num_disk; i > 0; i-- )
    {
        push( &pillar0, i );
    }
    
    for ( i = 1; i < ( 1 << num_disk ); i++, step++ )
    {
        source = ( i & ( i - 1 ) ) % 3;
        destination = ( ( i | ( i - 1 ) ) + 1 ) % 3;

        switch ( source )
        {
            case 0: disk_serial_num = pop( &pillar0 );
            break;

            case 1: disk_serial_num = pop( &pillar1 );
            break;

            case 2: disk_serial_num = pop( &pillar2 );
            break;
        }

        switch ( destination )
        {
            case 0: push( &pillar0, disk_serial_num );
            break;

            case 1: push( &pillar1, disk_serial_num );
            break;

            case 2: push( &pillar2, disk_serial_num );
            break;
        }

        printf( "\nStep %d : Move disk #%d from pillar '%d' to pillar '%d'\n", step, disk_serial_num, source, destination );
    }

    printf("\n\n");
    system("pause");
}

stack createStack()
{
    stack pillar;
    pillar.top = NULL;
    return pillar;
}

void push( stack *pillar, unsigned disk_serial_num )
{
    listNode* node = (listNode*) malloc( sizeof( listNode ) );
    node->data = disk_serial_num;
    node->link = pillar->top;
    pillar->top = node;
}

unsigned pop( stack *pillar )
{
    listNode* node = pillar->top;
    pillar->top = node->link;
    unsigned disk_serial_num = node->data;

    free( node );
    return disk_serial_num;
}