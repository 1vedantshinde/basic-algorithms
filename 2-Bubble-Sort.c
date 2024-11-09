#include<stdio.h>
int main(){

    int arr[5];
    int count_of_runs = 0;
    int swap_count = 0;
    printf("Enter 5 elements: \n");
    //takes input
    for(int i = 0; i < 5; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Elements in the array are: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    //bubble sort
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4 - i; ++j) {
            count_of_runs++;
            if(arr[j] > arr[j + 1]) {
                int ph = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = ph;
                swap_count++;
            }

        }
    }

    printf("Sorted Elements: ");

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nNumber of passes: %d\n", count_of_runs);
    printf("number of swaps: %d\n", swap_count);
}

