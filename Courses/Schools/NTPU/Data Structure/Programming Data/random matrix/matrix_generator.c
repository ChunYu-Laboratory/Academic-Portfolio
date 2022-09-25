#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include <string.h>

#define n 100000

void makeranmatrix(FILE *,char *,char *);

int main(void)
{
	    
	    
	    
        FILE *fptr1;
        char filename1[n];
        char filenameap1[20];
        FILE *fptr2;
        char filename2[n];
        char filenameap2[20];
		FILE *fptr3;
        char filename3[n];
        char filenameap3[20];
        FILE *fptr4;
        char filename4[n];
        char filenameap4[20];
        FILE *fptr5;
        char filename5[n];
        char filenameap5[20];
	    makeranmatrix(fptr1,filename1,filenameap1);	
        makeranmatrix(fptr2,filename2,filenameap2);	
        makeranmatrix(fptr3,filename3,filenameap3);
	    makeranmatrix(fptr4,filename4,filenameap4);	
        makeranmatrix(fptr5,filename5,filenameap5);

	    return 0; 





}







void makeranmatrix(FILE *fptr,char *filename,char *filenameap)

{        
          
          
          int i,j,m;
	      int valueM,valuem;
    	  int ranrow,rancol;
    	  int randommatrix[5000];
    	  
    	  
    	  
    	 
          printf("please input filename.\n");
	  scanf("%s",filenameap);
	  printf("\n");
	  fgets(filename,n,stdin);
	  fptr = fopen(filenameap, "w");
		  
		  
		  printf("Please input range of random number.input way:minvalue maxvalue\n");
    	  scanf("%d %d",&valuem,&valueM);
    	  printf("\n");
    	  printf("Please input row and col.input way:row col\n");
    	  scanf("%d %d",&ranrow,&rancol);
    	  printf("\n");
    	  
    	  
    	  srand((unsigned)time(NULL));
    	  
    	  
    	  
    	   
    	  for(i=0;i<ranrow;i++)
    	  {
    	  	for(j=0;j<rancol;j++)
    	  	
		{
		    randommatrix[i*rancol+j]=1;
    	        };
        
	  };
    	  
    	  
    	  
    	  
    	  for(i=0;i<=(ranrow*rancol-1)/5;i++)
    	  {
    	     m=0+(rand()%(((ranrow*rancol-1)-0)+1));
    	     randommatrix[m]=0;
	  };
    	  
    	  
    	  
    	  
    	  
    	  
		  
    	  for(i=0;i<ranrow;i++)
    	  {
    	  	
    	  	for(j=0;j<rancol;j++)
    	  	
		{
		     if((randommatrix[i*rancol+j])!=0)
	             {
		        randommatrix[i*rancol+j]=valuem+(rand()%((valueM-valuem)+1));
		     };
		      
		      
    	  	     printf("%d ",randommatrix[i*rancol+j]);
    	  	     fprintf(fptr,"%d ",randommatrix[i*rancol+j] );
		};
    	  	
    	  	printf("\n");
    	  	fprintf(fptr, "\n");
    	  	
          };
    	  fclose(fptr);
	
	
}
