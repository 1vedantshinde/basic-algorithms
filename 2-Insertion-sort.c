#include <stdio.h>

int main() {
    int n, i, j, num;
    int arr[100];
    int passes = 0;
    int swaps = 0;

    //input elements
    printf("Enter 5 elements: ");
    for(i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }

    // insertion sorting
    for (i = 1; i < 5; i++){
        num = arr[i];
        j = i - 1;
        passes++;
        while(j >= 0 && arr[j] > num){
            arr[j + 1] = arr[j];
            swaps++;
            j--;
        } 
        arr[j + 1] = num;
    }

    
    printf("Sorted array: ");
    for(i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("The number of passes: %d", passes);
    printf("\n");
    printf("The number of swaps: %d", swaps);

}

