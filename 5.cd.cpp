#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int spaceCount = 0, newlineCount = 0;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    file = fopen(filename, "r");

    // Check if the file exists
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ') {
            spaceCount++;
        } else if (ch == '\n') {
            newlineCount++;
        }
    }

    // Close the file
    fclose(file);

    // Print the results
    printf("Number of whitespaces: %d\n", spaceCount);
    printf("Number of newline characters: %d\n", newlineCount);

    return 0;
}
