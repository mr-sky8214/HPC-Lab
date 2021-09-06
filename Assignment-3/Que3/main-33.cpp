#include <omp.h>
#include <stdio.h>
#define n 1000

int main() {
    
  int a[n];
  int b[n];
  int c[n];
  int count = 0;
  double time = omp_get_wtime();
  omp_set_num_threads(4);
  #pragma omp parallel 
  {
    #pragma omp for nowait
    for(int i=0;i<1000;i++)
      a[i] = i;
    
    #pragma omp for nowait
    for(int i=0;i<1000;i++)
      b[i] = i;
  }
  
  #pragma omp parallel for schedule(static,200)
  for(int i=0;i<1000;i++) {
    c[i] = a[i] + b[i];
    
  }
  
  #pragma omp parallel for schedule(dynamic)
  for(int i=0;i<1000;i++) {
    c[i] = a[i] + b[i];
    
  }
  for(int i=0;i<1000;i++)
    printf("%d ",c[i]);
    
  printf("\n No of threads:  %d  and %f execution time",omp_get_max_threads(),omp_get_wtime() - time);
  
}

