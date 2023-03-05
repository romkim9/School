#include <stdio.h>

void hanoi(int n, char from, char tmp, char to){
  if(n > 0){
    if(n == 1){
      printf("원판 %d을 %c고리에서 %c고리로 옮기세요\n", n, from, to);
    }
    else{
      hanoi(n-1, from, to, tmp);
      printf("원판 %d을 %c고리에서 %c고리로 옮기세요\n", n, from, to);
      hanoi(n-1, tmp, from, to);
    }
  }
  else{
    printf("0보다 큰 숫자를 입력해주세요\n");
  }
}

int main(){
  int input;
  printf("고리의 개수를 입력하시오 : ");
  scanf("%d", &input);
  hanoi(input, 'A', 'B', 'C');
  return 0;
}