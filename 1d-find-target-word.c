#include<stdio.h>
#include<string.h>

int binarySearch(char words[100][100], int size, char *target){
    int first, last, mid;
    first = 0;
    last = size - 1;
    
    while(first <= last){
        mid = (first+last)/2;
        int count = strcmp(target, words[mid]);

        if(count == 0){
            return mid;
        } else if(count < 0){
            last = mid - 1;
        } else if(count > 0){
            first = mid + 1;
        }
    }

    if(first>last){
        return -1;
    }
}

int main(){

    char words[100][100], target[100];
    int size;

    printf("Enter number of words: ");
    scanf("%d", &size);

    printf("Enter words sorted alphabetically: ");
    for(int i = 0; i < size; i++){
        scanf("%s", words[i]);

    }
    printf("Enter target Word: ");
    scanf("%s", target);

    int index = binarySearch(words, size, target);
    if(index == -1){
        printf("Word is not in the array");

    } else {
        printf("Word found at index %d", index);
    }
}
