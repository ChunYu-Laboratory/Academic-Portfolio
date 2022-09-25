#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_STACK_SIZE 100
#define MAZE_ROW 12
#define MAZE_COL 12
#define EXIT_ROW 10
#define EXIT_COL 10


typedef struct
{
    short int vert;
    short int horiz;
} offsets;


typedef struct
{
    unsigned short int row;
    unsigned short int col;
    unsigned short int dir;
} element;


typedef struct listNode
{
    element data;
    struct listNode *link;
} listNode;


typedef struct
{
    listNode *top;
    short size;
} stack;


void setDirection( offsets * );

void mazeInput( bool [][MAZE_COL] );

void searchPath( bool [][MAZE_COL], element * , short int * , bool [][MAZE_COL], const offsets * );

stack createStack();

void push( element, element *, short int * );

element pop( element *, short int * );


int main()
{
    bool maze[MAZE_ROW][MAZE_COL];
    bool mark[MAZE_ROW][MAZE_COL] = {0};
    offsets move[8];
    short int top = 0;

    stack step = createStack();


    setDirection( move );
    mazeInput( maze );
    searchPath( maze, stack, &top, mark, move );


    printf("\n\n");
    system("pause");
}


void setDirection( offsets * move )
{
    move[0].vert = 0;
    move[0].horiz = 1;

    move[1].vert = 1;
    move[1].horiz = 1;

    move[2].vert = 1;
    move[2].horiz = 0;

    move[3].vert = 1;
    move[3].horiz = -1;

    move[4].vert = 0;
    move[4].horiz = -1;

    move[5].vert = -1;
    move[5].horiz = -1;

    move[6].vert = -1;
    move[6].horiz = 0;

    move[7].vert = -1;
    move[7].horiz = 1;
}


void mazeInput( bool maze[][MAZE_COL] )
{
    unsigned short int i, j;
    char filename[5];
    FILE *fptr;

    gets( filename );
    fflush( stdin );
    printf( "\n" );

    fptr = fopen( filename , "r" );


    for ( i = 0; i < MAZE_ROW; i++ )
    {
        for ( j = 0; j < MAZE_COL; j++ )
        {
            fscanf( fptr, "%d", &maze[i][j] );
        }
    }

    printf( "\nInput Maze : \n\n" );


    for ( i = 0; i < MAZE_ROW; i++ )
    {
        for ( j = 0; j < MAZE_COL; j++ )
        {
            printf( "%d ", maze[i][j] );
        }
        printf("\n");
    }

    fclose( fptr );
}


void searchPath( bool maze[][MAZE_COL], element * stack, short int * top, bool mark[][MAZE_COL], const offsets * move )
{
    unsigned short int row, col, nextRow, nextCol;
    unsigned short int i, j;
    unsigned short int dir = 0, count = 0, steps = 100, best_path;
    element position;
    bool found = false;


    mark[1][1] = 1;
    mark[EXIT_ROW][EXIT_COL] = 1;

    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 0;

    while ( *top > -1 )
    {
        position = pop( stack, top );

        row = position.row;
        col = position.col;
        dir = position.dir;

        while ( dir < 8 )
        {
            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;

            if ( nextRow == EXIT_ROW && nextCol == EXIT_COL )
            {
                found = true;

                count++;

                printf( "\nPath #%d :\n\n", count );
                printf( "Total Steps : %d\n\n", *top+2 );
                printf( "row col\n" );

                for ( i = 0; i <= *top; i++ )
                {
                    printf( "%2d%5d\n", stack[i].row, stack[i].col );
                }
                printf( "%2d%5d\n", row, col );
                printf( "%2d%5d\n\n", EXIT_ROW, EXIT_COL );


                for ( i = 0; i < MAZE_ROW; i++ )
                {
                    for ( j = 0; j < MAZE_COL; j++ )
                    {
                        if ( maze[i][j] == 1 )
                            printf( "+ " );
                        else if ( mark[i][j] == 1 )
                            printf( "@ " );
                        else
                            printf( "- " );
                    }
                    printf( "\n" );
                }


                if ( *top < steps )
                {
                    steps = *top;
                    best_path = count;
                }

                dir++;
            }
            else if ( !maze[nextRow][nextCol] && !mark[nextRow][nextCol] )
            {
                position.row = row;
                position.col = col;
                position.dir = ++dir;

                push( position, stack, top );

                mark[nextRow][nextCol] = 1;

                row = nextRow;
                col = nextCol;
                dir = 0;
            }
            else
            {
                dir++;
            }
        }

        mark[row][col] = 0;
    }

    if ( found )
        printf( "\nThe best path is path #%d\n", best_path );
    else
        printf( "\nThe maze does not have a path\n");
}


void push( element position, element * stack, short int * top )
{
    if ( *top >= MAX_STACK_SIZE-1 )
    {
        printf("Stack is full, cannot add element");
        exit(EXIT_FAILURE);
    }

    stack[++(*top)] = position;
}


element pop( element * stack, short int * top )
{
    if ( *top == -1 )
    {
        printf("stack is empty");
        exit(EXIT_FAILURE);
    }

    return stack[(*top)--];
}