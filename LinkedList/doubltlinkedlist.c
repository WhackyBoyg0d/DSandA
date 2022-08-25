#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * prev;
    struct Node * next;
};

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

int main()
{

    struct Node *N1;
    struct Node *N2;
    struct Node *N3;
    struct Node *N4;

    N1 = (struct Node *)malloc(sizeof(struct Node));
    N2 = (struct Node *)malloc(sizeof(struct Node));
    N3 = (struct Node *)malloc(sizeof(struct Node));
    N4 = (struct Node *)malloc(sizeof(struct Node));

    N1->data = 7;
    N1->next = N2;
    N1->prev = NULL;

    N2->data = 11;
    N2->next = N3;
    N2->prev = N1;

    N3->data =  121;
    N3->next = N4;
    N3->prev = N2;

    N4->data = 49;
    N4->next = NULL;
    N4->prev = N3;

    linkedListTraversal(N1);
 
  
    return 0;
}
