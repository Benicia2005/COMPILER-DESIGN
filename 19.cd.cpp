#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if the given character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '*' || ch == '(' || ch == ')' || ch == '$');
}

// Function to check if the given character is a non-terminal
int isNonTerminal(char ch) {
    return (ch == 'E' || ch == 'T' || ch == 'F');
}

// Function to get the leading set of a non-terminal
void getLeading(char nonTerminal, char leadingSet[]) {
    switch (nonTerminal) {
        case 'E':
            leadingSet[0] = '(';
            leadingSet[1] = 'id';
            break;
        case 'T':
            leadingSet[0] = '(';
            leadingSet[1] = 'id';
            break;
        case 'F':
            leadingSet[0] = '(';
            leadingSet[1] = 'id';
            break;
        default:
            break;
    }
}

// Function to compute the leading set for each non-terminal
void computeLeadingSets(char leadingSets[][10]) {
    int i;
    for (i = 0; i < 3; i++) {
        getLeading('E' + i, leadingSets[i]);
    }
}

// Function to perform operator precedence parsing
void operatorPrecedenceParser(char input[], char leadingSets[][10]) {
    char stack[100];
    int top = -1;
    int i = 0;

    // Push '$' to the stack to indicate the end
    stack[++top] = '$';

    printf("Parsing Table:\n");
    printf("Stack\t\tInput\t\tAction\n");

    while (i < strlen(input) || stack[top] != '$') {
        // Print current stack and input
        for (int j = 0; j <= top; j++) {
            printf("%c", stack[j]);
        }
        printf("\t\t");

        for (int j = i; j < strlen(input); j++) {
            printf("%c", input[j]);
        }
        printf("\t\t");

        // Get the leading set of the top of the stack
        char stackTop = stack[top];
        char leadingSet[10];
        getLeading(stackTop, leadingSet);

        // Check if the current input symbol is in the leading set
        if (strchr(leadingSet, input[i]) != NULL || (isNonTerminal(stackTop) && strchr(leadingSets[stackTop - 'E'], input[i]) != NULL)) {
            stack[++top] = input[i++];
            printf("Shift\n");
        } else {
            // Pop the top of the stack
            top--;
            printf("Reduce\n");
        }
    }

    // If the stack contains only '$' at the end, the input is accepted
    if (top == 0 && stack[top] == '$') {
        printf("\nInput accepted!\n");
    } else {
        printf("\nInput rejected!\n");
    }
}

int main() {
    char input[100];
    char leadingSets[3][10];

    computeLeadingSets(leadingSets);

    printf("Enter the input string: ");
    scanf("%s", input);

    operatorPrecedenceParser(input, leadingSets);

    return 0;
}

