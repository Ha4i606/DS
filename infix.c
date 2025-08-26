#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 20
char stack[MAX];
int top = -1;
void push(char c) 
{
    if (top < MAX - 1) 
    
    {
        top++;
        stack[top] = c;
    }
}

char pop() 
{
    if (top >= 0) 
    {
        char temp = stack[top];
        top--;
        return temp;
    }
    return '\0';
}

int precedence(char c) 
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

int main() 
{
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;
    char c;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') 
    {
        c = infix[i];

        if (isalnum(c)) 
        {
            postfix[j] = c;
            j++;
        } else if (c == '(') 
        {
            push(c);
        } else if (c == ')') 
        {
            while (top != -1 && stack[top] != '(') 
            {
                postfix[j] = pop();
                j++;
            }
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j] = pop();
                j++;
            }
            push(c);
        }
        i++;
    }

    while (top != -1) {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

