/*
    Program : Matrix Transpose
    # symbol A, B are Matrices
    Processing Synopsis : B = T(A)
    Matrix Data Input -> Transformation -> Abstract Data Structure
    Transpose A and store as B
    Abstract Data Structure -> Transformation -> Matrix Data Output
*/

#include <stdio.h>

#define MAX_TERMS 10001
#define MAX_COL 10001

typedef struct
{
    unsigned row;
    unsigned col;
    int value;
} term;


void fastTranspose( term *, term * );

void input( term * );

void output( term * );

int main()
{
    term a[MAX_TERMS], b[MAX_TERMS];
    unsigned i, j, current_element = 1;

    input( a );

    fastTranspose( a, b );

    output( b );

/* Process Display */

    printf( "Matrix a :\nRow Col Value\n" );

    for ( i = 0; i <= a[0].value; i++ )
    {
        printf( "%-4d %-4d %-4d\n", a[i].row, a[i].col, a[i].value );
    }
    printf("\n\n");

    printf( "\nMatrix T(a) :\nRow Col Value\n" );

    for ( i = 0; i <= b[0].value; i++ )
    {
        printf( "%-4d %-4d %-4d\n", b[i].row, b[i].col, b[i].value );
    }

    printf( "\nMatrix T(A) :\n" );

    for ( i = 0; i < b[0].row; i++ )
    {
        for ( j = 0; j < b[0].col; j++ )
        {
            if ( ( i == b[current_element].row ) && ( j == b[current_element].col ) )
            {
                printf( "%d ", b[current_element].value );

                current_element++;
            }
            else
            {
                printf( "%d ", 0 );
            }
        }

        printf( "\n" );
    }

    printf("\n\n");
    system("pause");
}


void fastTranspose( term * a, term * b )
{
    unsigned i;
    unsigned rowTerm[MAX_COL+1] = {0};

    rowTerm[0] = 1;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    if ( a[0].value > 0 )
    {
        for ( i = 1; i <= a[0].value; i++ )
        {
            rowTerm[a[i].col+1]++;
        }

        for ( i = 1; i < a[0].col; i++ )
        {
            rowTerm[i] += rowTerm[i-1];
        }

        for ( i = 1; i <= a[0].value; i++ )
        {
            b[rowTerm[a[i].col]].row = a[i].col;
            b[rowTerm[a[i].col]].col = a[i].row;
            b[rowTerm[a[i].col]].value = a[i].value;
            rowTerm[a[i].col]++;
        }
    }
}
/*
    Data Input by read file and Transformation
    ordinary matrix -> abstract data structure
    M is ordinary Matrix,
    m is representation by transforming M to abstract data structure
*/
void input( term * m_a )
{
    FILE *fptr;
    unsigned i, j;
    unsigned num_row_A, num_column_A;
    unsigned nonzero_count = 0, insert_row = 1;
    int current_element;
    char filename[10];

    /* input ordinary Matrix A */
    /* transform A to abstract data structure a */

    /* Matrix A */

    printf( "Input Filename of Matrix A : \n" );
    gets( filename );
    fflush( stdin );
    printf( "\nInput numbers of row and column of Matrix A : \n" );
    scanf( "%d %d", &num_row_A, &num_column_A );
    fflush( stdin );
    printf("\n");

    fptr = fopen( filename, "r" );

    m_a[0].row = num_row_A;
    m_a[0].col = num_column_A;

    for ( i = 0; i < num_row_A; i++ )
    {
        for ( j = 0; j < num_column_A; j++ )
        {
            fscanf( fptr, "%d", &current_element );

            if ( current_element != 0 )
            {
                m_a[insert_row].row = i;
                m_a[insert_row].col = j;
                m_a[insert_row].value = current_element;

                insert_row++;
                nonzero_count++;
            }
        }
    }

    m_a[0].value = nonzero_count;

    fclose( fptr );
}

/*
    Data Output stored as file and Transformation
    abstract data structure -> ordinary matrix
*/
void output( term * c )
{
    FILE *fptr;
    unsigned i, j;
    unsigned num_row_C = c[0].row, num_column_C = c[0].col;
    unsigned current_element = 1;

    fptr = fopen( "output_matrix", "w" );

    for ( i = 0; i < num_row_C; i++ )
    {
        for ( j = 0; j < num_column_C; j++ )
        {
            if ( ( i == c[current_element].row ) && ( j == c[current_element].col ) )
            {
                fprintf( fptr, "%d ", c[current_element].value );

                current_element++;
            }
            else
            {
                fprintf( fptr, "%d ", 0 );
            }
        }

        fprintf( fptr, "\n" );
    }

    fclose( fptr );
}