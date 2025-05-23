#include <stdio.h>

void showarray(int arr[], int n){
    printf("\n");
    for(int i = 0; i < n; i++){
        printf(" %d", arr[i]);
    }
}

int partition(int arr[], int low, int high){
    int start = low + 1;
    int end = high;
    int pivot = arr[low];
    int temp;

    while (1) {
        while (start <= high && arr[start] <= pivot) {
            start++;
        }
        while (end >= low && arr[end] > pivot) {
            end--;
        }

        if (start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        } else {
            temp = arr[low];
            arr[low] = arr[end];
            arr[end] = temp;
            return end;
        }
    }
}

void quicksort(int arr[], int low, int high){
    if (low < high) {
        int j = partition(arr, low, high);
        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
    }
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:");
    showarray(arr, n);

    quicksort(arr, 0, n - 1);

    printf("\nAfter sorting:");
    showarray(arr, n);

    return 0;
}
