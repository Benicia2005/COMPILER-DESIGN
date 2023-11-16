#include <stdio.h>

int main() {
    char input[100];
    char result[10], op1[10], op2[10], operator[5];

    printf("Enter an assignment statement: ");
    fgets(input, sizeof(input), stdin);

    // Parse the input expression
    sscanf(input, "%s = %s %s %s", result, op1, operator, op2);

    // Generate three-address code
    printf("%s = %s %s %s\n", result, op1, operator, op2);

    return 0;
}

