#include<stdio.h>

int binarySearch(int arr[], int low, int high, int x){
    while(low<=high){
        int mid = low + (high - low)/2;

        if(arr[mid] == x){
            return mid;
        }

        if(arr[mid] < x){//if x is greater, ignore the left half
            low = mid + 1;
        }

        if(arr[mid > x]){//if x is smaller, ignore the right half
            high = mid - 1;
        }
    }

    return -1;
}

int main(){
    int arr[] = {2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[10]);
    int x = 2;
    int result = binarySearch(arr, 0, n-1, x);
    if(result == -1){
        printf("The Element is not available in the array");

    } else {
        printf("Element is present at index %d", result);
    }
}
