#include <stdio.h>

void matrix_mult(int n, int a[3][3], int b[3][3], int c[3][3]){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      c[i][j] = 0;
      for(int k = 0; k < n; k++){
        c[i][j] = c[i][j] + a[i][k] * b[k][j];
      }
    }
  }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        printf("%3d", c[i][j]);
      }
      printf("\n");
    }
}

int main(){
  int a[3][3] = {1,1,1,2,2,2,3,3,3};
  int b[3][3] = {1,2,3,1,2,3,1,2,3};
  int c[3][3] = {0,};
  matrix_mult(3, a, b, c);
  return 0;
}

