#include <stdlib.h>   
#include <stdio.h>    
#include <omp.h>   

#define ARRAY_SIZE 8     
#define NUM_THREADS 3   

int main (int argc, char *argv[]) 
{

	int * a;
	int * b; 
	int * c;
        
    int n = ARRAY_SIZE;                 
	int total_threads = NUM_THREADS;      
	int i,x=46;     
	  
    a = (int *) malloc(sizeof(int)*n);
	b = (int *) malloc(sizeof(int)*n);
	c = (int *) malloc(sizeof(int)*n);


        for(i=0; i<n; i++) {
            a[i] = i;
        }
        for(i=0; i<n; i++) {
            b[i] = i;
        }   
        
	omp_set_num_threads(total_threads);
	

	#pragma omp parallel for firstprivate(x,a)
        for(i=0; i<n; i++) {
		c[i] = a[i]+b[i];
		printf("Thread %d works on element %d for x: %d\n", omp_get_thread_num(), i,x);
		x=i;
		printf("Thread %d works on element %d for x: %d\n", omp_get_thread_num(), i,x);

        }
	
	printf("i\ta[i]\t+\tb[i]\t=\tc[i]\n");
        for(i=0; i<n; i++) {
		printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);
        }
	
        free(a);  free(b); free(c);
	
	return 0;
}

