#include <omp.h>
#include <stdio.h>
#define n 1000
int main() {
    
  int a[n];
  int b[n];
  int c[n];
  double time = omp_get_wtime();
  
  
  for(int i=0;i<1000;i++)
      {
        a[i]=i;
        b[i]=i;
      }
  
  omp_set_num_threads(4);
  #pragma omp parallel for schedule(dynamic)
  for(int i=0;i<1000;i++) {
    c[i] = a[i] + b[i];
    
  }
  
  for(int i=0;i<1000;i++)
    printf("%d ",c[i]);
    
  printf("\n Using %d no of threads and %f execution time",omp_get_max_threads(),omp_get_wtime() - time);
  
}

