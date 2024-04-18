#include <stdio.h>
#include <string.h>

int priority(char a, char b) {
    if ((a == '+' && b == '-') || (a == '-' && b == '+')) {
        return 0;
    } else if ((a == '*' && b == '/') || (a == '/' && b == '*')) {
        return 1;
    } else if ((a == '+' && b == '/') || (a == '+' && b == '*') || (a == '-' && b == '/') || (a == '-' && b == '*')) {
        return 2;
    }
    return -1;
}

int operand(char a) {
    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) {
        return 0;
    } else {
        return 1;
    }
}

int isOperator(char a) {
    if (a == '+' || a == '-' || a == '*' || a == '/' || a == '^' || a == '(' || a == ')') {
        return 1;
    }
    return 0;
}

int check(char a, char operator[], int top) {
    if(a == "+" || a == "-")
    {
        int b = PMoperator(a,operator,top);
        return b;
    }
    return -1;
}

int PMoperator(char a, char operator[], int top) {
    if(operator[top] != "^")
    {
        if(a == operator[top])
        {
            return 3;
        }
        else
        {
            int b = priority(a,operator[top]);
            if(b == 0)
            {
                return 3;
            }
            else if (b == 1)
            {
                return 3;
            }
            else if (b == 2)
            {
                return 2;
            }
        }
    }
    return -1;
}

void push(char a, char stack[], int *top) {
    stack[++(*top)] = a;
}

void pop(int *top) {
    (*top)--;
}

void peek(char stack[], int *top) {
    printf("%c\n", stack[*top]);
}

char *postfix(char Equ[]) {
    static char equStack[100]; // Static because we'll return this array
    char operatorStack[100];
    int topES = -1, topOS = -1;
    for (int i = 0; Equ[i] != '\0'; i++) {
        if (!isOperator(Equ[i])) {
            push(Equ[i], equStack, &topES);
        } else if (isOperator(Equ[i])) {
            if (check(Equ[i],operatorStack,&topOS) == 2)
            {
                push(Equ[i],operatorStack,&topOS);
            }
            else if (check(Equ[i],operatorStack,&topOS) == 3)
            {
                push(operatorStack[i],equStack,&topES);
                pop(&topOS);
                push(Equ[i],operatorStack,&topOS);
            }
        } else {
            printf("Enter a correct Equation.\n");
            break;
        }
    }
    return equStack;
}

int main() {
    printf("Enter the Equation :");
    char Equ[100];
    scanf("%s", Equ);
    char *postfixEquation = postfix(Equ);
    printf("%s\n", postfixEquation);
    return 0;
}
