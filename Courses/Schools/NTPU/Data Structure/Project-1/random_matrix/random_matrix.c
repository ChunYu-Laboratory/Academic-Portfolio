#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void makeranmatrix();

int main()
{
	makeranmatrix();
}


void makeranmatrix()
{
	FILE *fptr;
	char filename[10];
	int i, j, m, rand_max_multiple_num;
	int valueM, valuem;
	int ranrow, rancol;
	int randommatrix[10000];


	printf("please input filename.\n");
	gets(filename);
	fflush(stdin);
	printf("\n");
	fptr = fopen( filename, "w" );


	printf( "Please input range of random number.input way : minvalue maxvalue\n" );
	scanf("%d %d", &valuem, &valueM);
	printf("\n");
	printf( "Please input row and col.input way : row col\n" );
	scanf("%d %d", &ranrow, &rancol);
	printf("\n");




	srand((unsigned)time(NULL));


	for (i = 0; i < ranrow; i++)
	{
		for (j = 0; j < rancol; j++)
		{
			randommatrix[i*rancol + j] = 1;
		}
	};


	for (i = 0; i <= (ranrow*rancol - 1) / 5; i++)
	{
		m = 0 + (rand() % (((ranrow*rancol - 1) - 0) + 1));
		randommatrix[m] = 0;
	};


	for (i = 0; i < ranrow; i++)
	{

		for (j = 0; j < rancol; j++)
		{
			if ((randommatrix[i*rancol + j]) != 0)
			{
				rand_max_multiple_num = 0 + (rand() % ((10000 - 0) + 1));
				randommatrix[i*rancol + j] = valuem + (rand()*rand_max_multiple_num % ((valueM - valuem) + 1));
			};
			fprintf(fptr, "%d ", randommatrix[i*rancol + j]);
		};

		fprintf(fptr, "\n");

	};
	fclose(fptr);
}
