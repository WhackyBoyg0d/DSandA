#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int f;
    int r;
    int *arr;
};


int isFull(struct Queue *q) {
    if(q->r + 1 == q->size){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct Queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue (struct Queue *q, int val ) {
    if(isFull(q)){
        printf("Queue Overflow");
    }
    else{
        
        q-> arr[q->r] = val;
        q->r = q->r + 1;
    }
}

int dequeue ( struct Queue *q ) {
    int val;
    if(isEmpty(q)){
        printf("Queue Underflow");
    }
    else{
        val = q -> arr[q->f];
        q -> f = q -> f + 1; 
    }
    printf("%d\n",val);
    return val;
}

int main() {
    struct Queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int*) malloc(q.size*sizeof(int));

    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    enqueue(&q, 12282032);
    enqueue(&q, 122);
    enqueue(&q, 123);
    if (isEmpty(&q))
    {
        printf("Queue is empty\n");
    }
    else{
        printf("isNot\n");
    }
    for (int i = 0; i < q.num; i++)
    {
        printf("%d\n", q.arr[i]);
    }

    return 0;
}