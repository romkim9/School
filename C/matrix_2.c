#include <stdio.h>

void matrix_mult(int a[2][3], int b[3][2], int c[2][2]){
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      c[i][j] = 0;
      for(int k = 0; k < 3; k++){
        c[i][j] = c[i][j] + a[i][k] * b[k][j];
      }
    }
  }
    for(int i = 0; i < 2; i++){
      for(int j = 0; j < 2; j++){
        printf("%3d", c[i][j]);
      }
      printf("\n");
    }
}

int main(){
  int a[2][3] = {{1,1,2},{2,2,3}};
  int b[3][2] = {{1,2},{1,2},{3,3}};
  int c[2][2] = {0,};
  matrix_mult(a, b, c);
  return 0;
}
