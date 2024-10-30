#include <stdio.h>
#include <stdlib.h>

int main(){
  int size;
  int *p;
  printf("사이즈 : "); scanf("%d", &size);
  
  p = (int *)malloc(size*sizeof(int));
  if(p==NULL){
    printf("메모리 부족\n");
    exit(1);
  }
  for(int i = 0; i < size; i++)
    p[i] = i;

  for(int i = 0; i < size; i++)
    printf("%d ", p[i]);

  printf("\n");
  free(p);
  return 0;
}
