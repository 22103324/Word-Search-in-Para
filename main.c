#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

void to_lowercase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char paragraph[1000];
    char words[MAX_WORDS][MAX_WORD_LEN];
    int word_count[MAX_WORDS] = {0};
    int num_words = 0;

    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    char* token = strtok(paragraph, " .,;:!\n");
    while (token != NULL) {
        to_lowercase(token);

        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(words[i], token) == 0) {
                word_count[i]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[num_words], token);
            word_count[num_words]++;
            num_words++;
        }

        token = strtok(NULL, " .,;:!\n");
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], word_count[i]);
    }

    return 0;
}
