#include <stdio.h>
#include <string.h>

int main() {
    char text[1000], word[100], temp[100];
    int i, j, n;
    int counted[1000] = {0};

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';

    n = strlen(text);

    for (i = 0; i < n; i++) {
   
        if (text[i] == ' ') {
            continue;
        }

        if (counted[i]) {
            while (i < n && text[i] != ' ') {
                i++;
            }
            continue;
        }

        int k = 0;
        while (i < n && text[i] != ' ') {
            word[k++] = text[i++];
        }
        word[k] = '\0';

        int count = 1;

        for (j = i; j < n; j++) {
           
            if (text[j] == ' ') {
                continue;
            }

            k = 0;
            while (j < n && text[j] != ' ') {
                temp[k++] = text[j++];
            }
            temp[k] = '\0';

           
            if (strcmp(word, temp) == 0) {
                count++;
                counted[j - k] = 1;
            }
        }
        printf("%s: %d\n", word, count);
    }
    return 0;
}

