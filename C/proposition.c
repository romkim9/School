#include <stdio.h>

void OR(int *a, int *b, int *result){
  printf("A | B | A V B\n");
  for(int i = 0; i < 4; i++){
    if(a[i] | b[i]) result[i] = 1;
    else result[i] = 0;
    printf("%d %3d %5d\n", a[i], b[i], result[i]);
  }
}

void AND(int *a, int *b, int *result){
  printf("A | B | A ^ B\n");
  for(int i = 0; i < 4; i++){
    if(a[i] & b[i]) result[i] = 1;
    else result[i] = 0;
    printf("%d %3d %5d\n", a[i], b[i], result[i]);
  }
}

void NOT(int *a, int *result){
  printf("A | ~A\n");
  for(int i = 0; i < 4; i++){
    result[i] = !a[i];
    printf("%d %3d\n", a[i], result[i]);
  }
}

void CON(int *a, int *b, int *result){
  printf("A | B | A -> B\n");
  for(int i = 0; i < 4; i++){
    if(!a[i] | b[i]) result[i] = 1;
    else result[i] = 0;
    printf("%d %3d %5d\n", a[i], b[i], result[i]);
  }
}

int main(){
  int p[4] = {1, 1, 0, 0}, q[4] = {1, 0, 1, 0};
  int i = 0;
  int result[4] = {0};

  CON(&p,&q,&result);
  
  return 0;
}
