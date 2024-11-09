#include<stdio.h>

int findSmallestMissingPositive(int arr[], int size){
    int i, missing_num, start = 0;
    for(i = 0; i <= size - 1; i++){
        if(arr[i] > 0){
            missing_num = arr[i];
            start = i;
            break;
        }
    }
    for(i = start; i <= size - 1; i++){
        if(missing_num != arr[i]){
            continue;
        } else {
            missing_num += 1;
        }
    }
    return missing_num;
}

int checkArray(int arr[], int size){
    int x = 0;
    for(int i = 0; i < size - 1; i++){
        if(arr[i] > arr[i+1]){
            x = 1;
            break;
        }
    }
    return x;
}

int main(){
    int arr[100];
    int n, i, smallest_int;

    printf("Enter size of the array: ");
    scanf("%d", &n);

    printf("Enter the numbers: \n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    if(checkArray(arr, n) == 1){
        printf("The array has not been sorted\n");
    } else {
        smallest_int = findSmallestMissingPositive(arr, n);

        if(smallest_int != 0){
            printf("The smallest missing positive integer is %d\n", smallest_int);

        } else {
            printf("All the numbers are negative integers");
        }
    }
}
