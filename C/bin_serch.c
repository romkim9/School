#include <stdio.h>

int bin_search(int n, int s[], int x){
  int low, high, mid, cnt, location;
  low = 0;
  high = n;
  location = -1;
  cnt = 0;

  while(low <= high && location == -1){
    mid = (low+high) / 2;

    if (x == s[mid])
      location = mid;
    else if(x < s[mid])
      high = mid - 1;
    else
      low = mid + 1;
    cnt++;
    
    printf("%d | mid = %d\n", cnt, mid);
  }
  return cnt;
}

int main(){
  int arr[14] = {2, 5, 8, 12, 18, 22, 25, 29, 35, 38, 45, 50, 64, 76}, cnt;
  cnt = bin_search(sizeof(arr)/4 -1, arr, 8);

  printf("총 연산 횟수는 %d", cnt);
  return 0;
}



