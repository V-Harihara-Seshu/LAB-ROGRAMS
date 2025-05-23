#include <stdio.h>

void showarray(int arr[],int size){
    printf("\n");
    for(int i = 0; i < size; i++){
        printf(" %d", arr[i]);
    }
}

void merge(int arr[],int low, int mid, int high){
    int left = low;
    int right = mid+1;
    int k = low;
    int b[10];

    while(left <= mid && right <= high){
        if(arr[left] < arr[right]){
            b[k++] = arr[left++];
        }
        else{
            b[k++] = arr[right++];
        }
    }
    while(left <= mid){
        b[k++] = arr[left++];
    }
    while(right <= high){
        b[k++] = arr[right++];
    }
    for(int i = low; i <= high; i++){
        arr[i] = b[i];
    }
}

void mergesort(int arr[],int low, int high){
    if( low < high){
        int mid = (low + high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    int arr[] = {5,4,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    showarray(arr,size);
    mergesort(arr,0,size-1);
    showarray(arr,size);
}
