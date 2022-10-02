#include <stdio.h>
#include <stdlib.h>

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
        // printf("%d\n", ptr->arr[ptr->top]);
        ptr->top--;
        return val;
    }
    
}

void addQueue(struct stack *ptr1, struct stack *ptr2, int i){
    if (isEmpty(ptr1)){
        push(ptr1, i);
    }
    else{
        while(!isEmpty(ptr1)){
            int val = pop(ptr1);
            push(ptr2, val);
        }
        push(ptr1, i);
    }
    while(!isEmpty(ptr2)){
            int val = pop(ptr2);
            push(ptr1, val);
        }
}

int main()
{
    struct stack *sp1 = (struct stack *)malloc(sizeof(struct stack));
    sp1->size = 5;
    sp1->top = -1;
    sp1->arr = (int *)malloc(sp1->size * sizeof(int));

    struct stack *sp2 = (struct stack *)malloc(sizeof(struct stack));
    sp2->size = 5;
    sp2->top = -1;
    sp2->arr = (int *)malloc(sp2->size * sizeof(int));

    addQueue(sp1, sp2, 1);
    addQueue(sp1, sp2, 2);
    addQueue(sp1, sp2, 3);
    addQueue(sp1, sp2, 4);
    addQueue(sp1, sp2, 5);

    // push(sp1,1);
    // push(sp1, 2);  
    // push(sp1, 3);
    // push(sp1, 4);
    int x = sp1->top;
    for (int l = 0; l <= x; l++)
    {
        int val = pop(sp1);
        printf("%d\n",val);
    }

    return 0;
}