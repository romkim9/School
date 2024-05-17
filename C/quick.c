#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 피벗을 배열의 마지막 요소로 선택
    int i = (low - 1); // 인덱스 i를 피벗의 위치보다 하나 앞으로 설정

    for (int j = low; j <= high - 1; j++) {
        // 현재 요소가 피벗보다 작으면, 인덱스 i를 증가시키고 현재 요소와 arr[i]를 교환
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // 피벗을 올바른 위치에 두기 위해 피벗과 arr[i+1]을 교환
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 퀵 정렬 함수
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 분할하여 피벗을 기준으로 배열을 두 개의 부분 배열로 나눔
        int pi = partition(arr, low, high);

        // 분할된 두 부분 배열에 대해 재귀적으로 퀵 정렬을 수행
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 퀵 정렬을 실행하는 메인 함수
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

