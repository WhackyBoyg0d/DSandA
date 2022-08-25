#include <stdlib.h>
#include <stdio.h>


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



int parenthesisMatch(char  exp[] ) {
    struct stack* sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for(int i = 0; exp[i]!='\0'; i++){
        if(exp[i] == '('){
            push(sp, '(');
            
        }
        else if (exp[i] == ')'){
            pop(sp);
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

int main()
{
    char  exp[] = "(2(1+1))";
    if(parenthesisMatch(exp)){
        printf("yes");
    }
    else{
        printf("no");
    }
    return 0;
}