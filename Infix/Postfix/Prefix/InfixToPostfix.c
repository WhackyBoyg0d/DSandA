#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow !!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow !!\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int stackTop(struct stack *sp) {
    return sp->arr[sp->top];
}

int match(char a, char b)
{
    if ((a == '{' && b == '}') || (a == '(' && b == ')') || (a == '[' && b == '}'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int parenthesisMatch(char exp[])
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            char popped_ch = pop(sp);
            if (!match(exp[i], popped_ch))
            {
                return 0;
            }
        }
    }
    if (isEmpty(sp))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

char * InfixToPostfix(char *infix) {
    struct stack * sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc((strlen(infix)+1)* sizeof(char)); 
    int i = 0;
    int j = 0;
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i])){

        }
    }
}

int main()
{
    
    return 0;
}