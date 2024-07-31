#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

// Function to convert a string to lowercase
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

    // Get paragraph input from the user
    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Tokenize the paragraph into words
    char* token = strtok(paragraph, " .,;:!\n");
    while (token != NULL) {
        to_lowercase(token);

        // Check if the word already exists in the words array
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(words[i], token) == 0) {
                word_count[i]++;
                found = 1;
                break;
            }
        }

        // If the word is not found, add it to the words array
        if (!found) {
            strcpy(words[num_words], token);
            word_count[num_words]++;
            num_words++;
        }

        token = strtok(NULL, " .,;:!\n");
    }

    // Print the word frequencies
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], word_count[i]);
    }

    return 0;
}
