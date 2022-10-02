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

void push(struct stack *ptr, struct stack *ptr1, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow !!\n");
    }
    else
    {
        if (isEmpty(ptr) || ptr1->arr[ptr1->top] > val)
        {
            ptr1->top++;
            ptr1->arr[ptr1->top] = val;
        }
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
   
}

int pop(struct stack *ptr, struct stack *ptr1)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow !!\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        if (val == ptr1->arr[ptr1->top]){
            ptr1->top--;
        }
            // printf("%d\n", ptr->arr[ptr->top]);
            ptr->top--;
        return val;
    }
}

int FindMin(struct stack *ptr, struct stack *ptr1)
{
    if(isEmpty(ptr)){
        printf("Stack'sempty");
    }
    else{
        return ptr1->arr[ptr1->top];
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

    // push(sp1, sp2, 1);
    push(sp1, sp2, 2);
    push(sp1, sp2, 3);
    push(sp1, sp2, 4);

    printf("%d\n",FindMin(sp1, sp2));
  
    

    return 0;
}