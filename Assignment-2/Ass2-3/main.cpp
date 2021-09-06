#include <omp.h>
#include <stdio.h>
#include<stdlib.h>
#define n 8


int main() {

    int *a;
    int *b;
    a=(int*)malloc(n*sizeof(int));
    b=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
    	a[i]=i;
	}
	int x=5,y=50;
	omp_set_num_threads(3);
	#pragma omp parallel for firstprivate(a,y)
	for(int i = 0;i < n;i++) {
		b[i]=a[i]+x;
		printf("\nThread number %d, executing iteration %d for y:%d",omp_get_thread_num(),i,y);	
		y=i;
		printf("\nThread number %d, executing iteration %d for y:%d",omp_get_thread_num(),i,y);	
	
	}
	
		printf("\ni\ta[i]\t+x\t=\tc[i]\n");
        for(int i=0; i<n; i++) {
		printf("%d\t%d\t%d\t=\t%d\n", i, a[i],x,b[i]);
        }
	
}
