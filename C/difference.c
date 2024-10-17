#include <stdio.h>
// 합집합
void Union(int A[], int B[]){
  int U[10] = {0};
  int i = 0, flag = 0;
  for(int i = 0; i < sizeof(A)/sizeof(int); i++){
    U[i] = A[i];
  }
  
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
      if(U[j] != B[i]){
        flag++;
      }
    }
    if(flag){
      U[sizeof(A)/sizeof(int)+i] = B[i];
    }
  }

  printf("Union : ");
  for(int i = 0; i < 10; i++){
    if(U[i] != 0){
      printf("%d ", U[i]);
    }
  }
  printf("\n");
}

// 교집합
void intersection(int A[], int B[]){
  int I[10] = {0};
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
      if(A[j] == B[i]){
        I[i] = B[i];
      }
    }
  }

  printf("intersection : ");
  for(int i = 0; i < 3; i++){
    if(I[i] != 0){
      printf("%d ", I[i]);
    }
  }
  printf("\n");
}

// 차집합
void diffrence(int A[], int B[]){
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
      if(A[j] == B[i]){
        A[j] = 0;
      }
    }
  }

  printf("diffrence : ");
  for(int i = 0; i < 3; i++){
    if(A[i] != 0){
      printf("%d ", A[i]);
    }
  }
  printf("\n");
}


int main(){
  int A[3] = {1, 2 ,3};
  int B[2] = {3, 4};
  Union(A,B);
  intersection(A,B);
  diffrence(A,B);

  
  return 0;
}


