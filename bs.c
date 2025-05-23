#include <stdio.h>

void bsi(int arr[],int size,int key){
    int low = 0;
    int high = size - 1;
    int mid;
    while(low <= high){

        mid = (low + high )/ 2;
        if(arr[mid] == key){
            break;
        }
        if(key < arr[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    if(arr[mid] == key){
        printf(" key %d found at index %d\n",key,mid);
    }
    else{
        printf(" key %d not found\n",key);
    }
    }

void bsr(int  arr[],int low,int high, int key){

    int mid;
    if(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == key){
            printf("\n%d found at %d",key,mid);
            return;
        }
        if(key < arr[mid]){
            bsr(arr,low,mid-1,key);
        }
        else{
            bsr(arr,mid+1,high,key);
        }
    }
    if(low > high){
        printf(" \nKey not found ");
    }
}
int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    bsi(arr,size,3);
    bsi(arr,size,8);
    bsr(arr,0,size-1,3);
    bsr(arr,0,size-1,8);
    return 0;
}
