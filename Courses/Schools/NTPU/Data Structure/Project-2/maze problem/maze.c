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


void setDirection( offsets * );

void mazeInput( short int [][MAZE_COL] );

void path( short int [][MAZE_COL], element * , short int * , bool [][MAZE_COL], const offsets * );

void push( element, element *, short int * );

element pop( element *, short int * );


int main()
{
    short int maze[MAZE_ROW][MAZE_COL];
    bool mark[MAZE_ROW][MAZE_COL] = {0};
    offsets move[8];
    short int top = 0;
    element stack[MAX_STACK_SIZE];

    setDirection( move );
    mazeInput( maze );
    path( maze, stack, &top, mark, move );

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

void mazeInput( short int maze[][MAZE_COL] )
{
    unsigned short int i, j;
    char filename[5];
    FILE *fptr;

    gets( filename );
    fflush( stdin );

    fptr = fopen( filename , "r" );


    for ( i = 0; i < MAZE_ROW; i++ )
    {
        for ( j = 0; j < MAZE_COL; j++ )
        {
            fscanf( fptr, "%d", &maze[i][j] );
        }
    }


    for ( i = 0; i < MAZE_ROW; i++ )
    {
        for ( j = 0; j < MAZE_COL; j++ )
        {
            printf( "%d ", maze[i][j] );
        }
        printf("\n");
    }

}

void path( short int maze[][MAZE_COL], element * stack, short int * top, bool mark[][MAZE_COL], const offsets * move )
{
    unsigned short int row = 2, col = 2, nextRow, nextCol, count = 0, steps = 100, best_path;
    unsigned i, j;
    element position;
    unsigned short int dir = 0;
    bool found = false;

    mark[1][1] = 1;

    stack[0].row = 1;
    stack[0].col = 1;
    stack[0].dir = 0;

    while ( *top > -1 )
    {
        mark[row][col] = 0;
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
                printf("path #%d:\n",++count);
                printf("row col\n");
                for( i = 0; i <= *top; i++)
                    printf("%2d%5d\n",stack[i].row, stack[i].col);
                printf("%2d%5d\n",row,col);
                printf("%2d%5d\n",EXIT_ROW,EXIT_COL);
                if(*top < steps)
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
    }

    if ( found )
        printf("The best path is path #%d", best_path);
    else
        printf("The maze does not does not have a path\n");
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