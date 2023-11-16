#include <stdio.h>
#include <ctype.h>

// Function to check if the character is an operator
int isOperator(char symbol) {
    return (symbol == '+' || symbol == '*' || symbol == '(' || symbol == ')');
}

// Function to get the precedence of an operator
int getPrecedence(char symbol) {
    switch (symbol) {
        case '+':
            return 1;
        case '*':
            return 2;
        case '(':
            return 0; // '(' has the lowest precedence
        default:
            return -1; // Invalid operator
    }
}

// Function to perform the operator precedence parsing
void operatorPrecedenceParser(char input[]) {
    char stack[50];
    int top = -1;

    printf("Symbol\t\tStack\n");

    for (int i = 0; input[i] != '\0'; i++) {
        // Print current symbol and stack
        printf("%c\t\t", input[i]);
        for (int j = 0; j <= top; j++) {
            printf("%c", stack[j]);
        }
        printf("\n");

        // If the current symbol is an operand, print it and push it onto the stack
        if (!isOperator(input[i])) {
            printf("\t\tShift\n");
            top++;
            stack[top] = input[i];
        } else {
            // If the stack is not empty and the precedence of the current symbol is less than or equal to the
            // precedence of the top of the stack, pop and print the stack until a lower precedence is encountered
            while (top >= 0 && getPrecedence(input[i]) <= getPrecedence(stack[top])) {
                printf("\t\tReduce by %c\n", stack[top]);
                top--;
            }
            // Push the current symbol onto the stack
            top++;
            stack[top] = input[i];
        }
    }

    // Pop and print the remaining symbols from the stack
    while (top >= 0) {
        printf("\t\tReduce by %c\n", stack[top]);
        top--;
    }
}

int main() {
    char input[50];

    // Get input from the user
    printf("Enter an expression: ");
    scanf("%s", input);

    // Add $ to the end of the input to indicate the end of the expression
    int len = 0;
    while (input[len] != '\0') {
        len++;
    }
    input[len] = '$';
    input[len + 1] = '\0';

    // Perform operator precedence parsing
    operatorPrecedenceParser(input);

    return 0;
}
