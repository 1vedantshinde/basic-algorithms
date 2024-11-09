#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void copyArray(int arr1[], int arr2[], int size){
    for(int i = 0; i < size; i++){
        arr2[i] = arr1[i];
    }
}

void Swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;

}

int Partition(int arr[], int low, int high){
    int i, j, pivot;

    pivot = arr[low];
    i = low + 1;
    j = high;

    do{
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }

        if(i < j){
            Swap(&arr[i], &arr[j]);
        }
    } while(i < j);

    Swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int x = Partition(arr, low, high);
        quickSort(arr, low, x - 1);
        quickSort(arr, x+1, high);
    }
}

void merge(int arr[], int low, int mid, int high){
    int i, j, k, n, m;
    n = mid - low + 1;
    m = high - mid;
    int temp1[n], temp2[m];

    for(i = 0; i < n; i++){
        temp1[i] = arr[low + i];
    }

    for(j = 0; j < m; j++){
        temp2[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = low;

    while(i < n && j < m){
        if(temp1[i] < temp2[j]){
            arr[k] = temp1[i];
            i++;
        } else {
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }

    while(i < n){
        arr[k] = temp1[i];
        i++;
        k++;
    }

    while(j < m){
        arr[k] = temp2[j];
        j++;
        k++;

    }
}

void mergeSort(int arr[], int low, int high){
    int mid;
    if(low < high){
        mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main(){
    int size = 100000;
    int arr[size];
    int arr1[size];
    int arr2[size];
    int low = 0;
    int high = size - 1;

    srand(time(NULL));

    for(int i =  0; i < size; i++){
        arr[i] = rand() % 100;

    }

    copyArray(arr, arr1, size);
    copyArray(arr, arr2, size);

    clock_t start = clock();
    mergeSort(arr1, low, high);
    clock_t end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for merge sort = %.2lf\n", time);

    clock_t start1 = clock();
    quickSort(arr2, low, high);
    clock_t end1 = clock();
    double time1 = ((double)(end1 - start1)) / CLOCKS_PER_SEC;
    printf("Time taken for quick sort = %.2lf\n", time1);

}
