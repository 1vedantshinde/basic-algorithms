#include<stdio.h>
int main(){
    int arr[5];
    printf("Enter 5 elements: \n");
    for(int i = 0; i < 5; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Elements in the array are: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    for(int i = 0; i < 4; i++) {
        int min = i;
        for(int j = i + 1; j < 5; j++) {
            if(arr[j] < arr[min]) {
            min = j;
            }
        }
        int ph = arr[min];
        arr[min] = arr[i];
        arr[i] = ph;
    }
    printf("Sorted Elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
}
