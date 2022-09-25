/*
    Program : Matrix Multiplication

    # symbol A, B, C are Matrices

    Processing Synopsis : A x B = C

    Matrix Data Input -> Transformation -> Abstract Data Structure

    Multiply A and Transpose( B ) stored as C

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

void Multiplication( term *, term *, term * );

void storeSum( term * , unsigned * , unsigned , unsigned , int * );

int compare( int, int );

void input( term * , term * );

void output( term * );

int main()
{
    term a[MAX_TERMS], b[MAX_TERMS], c[MAX_TERMS];
    unsigned i, j, current_element = 1;

    input( a, b );

    Multiplication( a, b, c );

    output( c );

/* Process Display */

    printf( "Matrix a :\nRow Col Value\n" );

    for ( i = 0; i <= a[0].value; i++ )
    {
        printf( "%-4d %-4d %-4d\n", a[i].row, a[i].col, a[i].value );
    }
    printf("\n\n");

    printf( "Matrix b :\nRow Col Value\n" );

    for ( i = 0; i <= b[0].value; i++ )
    {
        printf( "%-4d %-4d %-4d\n", b[i].row, b[i].col, b[i].value );
    }
    printf("\n\n");

    printf( "\nMatrix axb :\nRow Col Value\n" );
    
    for ( i = 0; i <= c[0].value; i++ )
    {
        printf( "%-4d %-4d %-4d\n", c[i].row, c[i].col, c[i].value );
    }

    printf( "\nMatrix AxB :\n" );

    for ( i = 0; i < c[0].row; i++ )
    {
        for ( j = 0; j < c[0].col; j++ )
        {
            if ( ( i == c[current_element].row ) && ( j == c[current_element].col ) )
            {
                printf( "%d ", c[current_element].value );

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

/* AxB = C */
void Multiplication( term * a, term * b, term * c )
{
    unsigned i, j;
    unsigned rows_A = a[0].row, cols_A = a[0].col, total_A = a[0].value;
    unsigned rows_B = b[0].row, cols_B = b[0].col, total_B = b[0].value;
    unsigned total_C = 0;
    unsigned row = a[1].row, column;
    unsigned row_begin = 1;
    int sum = 0;
    term new_B[MAX_TERMS];

    /* error handling */
    if ( cols_A != rows_B )
    {
        fprintf( stderr, "Incompatible matrices\n" );
        exit(1);
    }

    fastTranspose( b, new_B );

    /* set boundary condition */
    a[total_A+1].row = rows_A;
    new_B[total_B+1].row = cols_B;
    new_B[total_B+1].col = 0;

    for ( i = 1; i <= total_A; )
    {
        column = new_B[1].row;

        /* multiply row of a by column of b */
        for ( j = 1; j <= total_B+1; )
        {
            if ( a[i].row != row )
            {
                storeSum( c, &total_C, row, column, &sum );

                i = row_begin;
                for ( ; new_B[j].row == column; j++ );
                column = new_B[j].row;
            }
            else if ( new_B[j].row != column )
            {
                storeSum( c, &total_C, row, column, &sum );

                i = row_begin;
                column = new_B[j].row;
            }
            else switch ( compare( a[i].col, new_B[j].col ) )
            {
                case -1:    /* go to next term in a */
                    i++;
                    break;
                
                case 0:    /* add terms, go to next term in a and b */
                    sum += ( a[i++].value * new_B[j++].value );
                    break;
                
                case 1:    /* go to next term in b */
                    j++;
            }
        }   /* end of for j <= total_B+1 */

        for ( ; a[i].row == row; i++ );

        row_begin = i;
        row = a[i].row;

    }   /* end of for i <= total_A */

    c[0].row = rows_A;
    c[0].col = cols_B;
    c[0].value = total_C;
}

/*
    if *sum != 0, then it along with its row and column position
    is stored as the (*total_C)+1 entry in c
*/
void storeSum( term * c, unsigned * total_C, unsigned row, unsigned column, int * sum )
{
    if ( *sum )
    {
        if ( *total_C < MAX_TERMS )
        {
            c[++(*total_C)].row = row;
            c[*total_C].col = column;
            c[*total_C].value = *sum;

            *sum = 0;
        }

        /* error handling */
        else
        {
            fprintf( stderr, "Numbers of terms in product exceeds %d\n", MAX_TERMS );
            exit(1);
        }
    }
}

int compare( int x, int y )
{
    if ( x < y )    return -1;
    else if ( x > y )   return 1;
    else    return 0;
}

/*
    Data Input by read file and Transformation

    ordinary matrix -> abstract data structure

    M is ordinary Matrix,
    m is representation by transforming M to abstract data structure
*/
void input( term * m_a, term * m_b )
{
    FILE *fptr;
    unsigned i, j;
    unsigned num_row_A, num_column_A, num_row_B, num_column_B;
    unsigned nonzero_count = 0, insert_row = 1;
    int current_element;
    char filename[10];

    /* input ordinary Matrix A and B */
    /* transform A and B to abstract data structure a and b */

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

    /* reset flag */
    nonzero_count = 0;
    insert_row = 1;


    /* Matrix B */

    printf( "Input Filename of Matrix B : \n" );
    gets( filename );
    fflush( stdin );
    printf( "\nInput numbers of row and column of Matrix B : \n" );
    scanf( "%d %d", &num_row_B, &num_column_B );
    fflush( stdin );
    printf("\n");

    fptr = fopen( filename, "r" );

    m_b[0].row = num_row_B;
    m_b[0].col = num_column_B;

    for ( i = 0; i < num_row_B; i++ )
    {
        for ( j = 0; j < num_column_B; j++ )
        {
            fscanf( fptr, "%d", &current_element );

            if ( current_element != 0 )
            {
                m_b[insert_row].row = i;
                m_b[insert_row].col = j;
                m_b[insert_row].value = current_element;

                insert_row++;
                nonzero_count++;
            }
        }
    }

    m_b[0].value = nonzero_count;

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