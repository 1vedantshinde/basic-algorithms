#include <stdio.h>

void merge(int arr[], int mid, int low, int high) {
    int i, j, k;
    int n1 = mid - low + 1; 
    int n2 = high - mid; 

    int Ltemp[n1], Rtemp[n2];
    for (i = 0; i < n1; i++)
        Ltemp[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        Rtemp[j] = arr[mid + 1 + j];

    
    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2) {
        if (Ltemp[i] <= Rtemp[j]) {
            arr[k] = Ltemp[i];
            i++;
        }
        else {
            arr[k] = Rtemp[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        arr[k] = Ltemp[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = Rtemp[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) { 
        int mid = low + (high - low) / 2; 

        mergeSort(arr, low, mid); 
        mergeSort(arr, mid + 1, high); 
        merge(arr, mid, low, high); 
    }
}

void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int arr[] = {23, 1, 500, -5, 4};

    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    return 0;
}

