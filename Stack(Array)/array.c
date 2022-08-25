#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top ==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main() {
    // struct stack S;
    // S.size = 80;
    // S.top = -13;
    // S.arr = (int*)malloc(S.size*sizeof(int));
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    s->arr[0] = 7;
    s->top++; 
    if(isEmpty(s)){
        printf("The stack is empty");
    }else{
        printf("Not empty");
    }
 
}