#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

int isEmpty(struct Node* top) {
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node *top  )
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node* push(struct Node* top, int x){
    if(isFull(top)){
        printf("Stack Overflow!!\n");
    }
    else{
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node *top)
{
    if (isEmpty(top)){
        printf("Stack Underflow!!\n");
    }
    else
    {
        struct Node * n = top;
        top = top->next;
        int x = n-> data;
        free(n);
        return x;
    }
}

int peek(struct Node *top, int pos){
    struct Node *ptr = top;
    int x = 1;
    while(x!=pos){
        ptr = ptr->next;
        x = x+1;
    }
    if(ptr != NULL){
    return ptr->data;
    }

}

int stackTop(struct Node *top)
{
    return top->data;
}

int stackBottom(struct Node *top)
{
    struct Node *ptr = top;
    int x;
    while(ptr!=NULL){
        x = ptr->data;
        ptr = ptr->next;
    }
    return x;
}

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    // printf("\n%d", ptr->data);
    // ptr = ptr->next;
    while (ptr != NULL)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    struct Node* top = NULL;
    top = push(top, 78);
    top = push(top, 79);
    top = push(top, 80);
    top = push(top, 81); 
    // linkedListTraversal(top);
   /* pop(top); */  
    printf("%d\n",peek(top, 2));
    printf("%d\n", stackTop(top));
    printf("%d\n", stackBottom(top));

    return 0;
}