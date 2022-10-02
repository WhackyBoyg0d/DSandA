#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    // int num;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q)
{
    if (q->r + 1 == q->size)
    {
        return 1;
    }
    else
    {
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

void enqueue(struct Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Overflow");
    }
    else
    {

        q->arr[q->r] = val;
        q->r = q->r + 1;
        // q->num+=1;
    }
}

int dequeue(struct Queue *q)
{
    int val;
    if (isEmpty(q))
    {
        printf("Queue Underflow");
    }
    else
    {
        val = q->arr[q->f];
        q->f = q->f + 1;
        // q->num -= 1;
    }
    // printf("%d\n", val);
    return val;
}

void StackAdd(int i, struct Queue *q1, struct Queue *q2){
    if (isEmpty(q1)){
        enqueue(q1, i);
    }
    else{
        for(int j = q1->f; j<q1->r; j++){
            int val = dequeue(q1);
            enqueue(q2, val);
        }
        enqueue(q1, i);
    }
    for (int j = q2->f; j < q2->r; j++)
    {
        int val = dequeue(q2);
        enqueue(q1, val);
    }
}


    int main()
{
    struct Queue q1;
    q1.size = 100;
    // q1.num = -1;
    q1.f = q1.r = -1;
    q1.arr = (int *)malloc(q1.size * sizeof(int));

    struct Queue q2;
    q2.size = 100;
    // q1.num = 0;
    q2.f = q2.r = -1;
    q2.arr = (int *)malloc(q2.size * sizeof(int));

    StackAdd(1,&q1, &q2);
    StackAdd(2, &q1, &q2);
    // StackAdd(3, &q1, &q2);
    
    StackAdd(4, &q1, &q2);
    // enqueue(&q1, 3);
    // enqueue(&q1, 2);
    // enqueue(&q1, 1);
    // printf("%d\n", q1.f);
    // printf("%d\n", q1.r);
    for(int i = q1.f; i< q1.r; i++ ){
        printf("%d\n",q1.arr[i]);
    }

    return 0;
}