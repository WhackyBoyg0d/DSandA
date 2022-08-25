#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

int isFull(struct stack*ptr){
    if(ptr->top == ptr->size -1){
        return 1;
    }
    return 0;
}


int isEmpty(struct stack *ptr){
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow !!\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow !!\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        printf("%d\n", ptr->arr[ptr->top]);
        ptr->top--;
        }
}

int peek(struct stack *ptr){
    
}

int main () {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size *sizeof(int));
    printf("Stack created\n");

    printf("%d\n",isEmpty(sp));
    printf("%d\n",isFull(sp));

    push(sp, 56);

    printf("%d\n", isEmpty(sp));
    printf("%d\n", isFull(sp));

    pop(sp);

    printf("%d\n", isEmpty(sp));
    printf("%d\n", isFull(sp));

    pop(sp);

    return 0;
}