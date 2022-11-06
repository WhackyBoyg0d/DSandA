#include <iostream>

using namespace std;

struct Node
{

    int data;
    struct Node *next;
};

void linkedListTraversal(Node *head)
{
    Node *ptr = head;
    // printf("\n%d", ptr->data);
    // ptr = ptr->next;
    while (ptr != NULL)
    {
        cout << ptr->data<<endl;;
        ptr = ptr->next;
    }
}

void tail_insert(Node *&head,
                 Node *&tail, int num)
{
    Node *p = new Node;
    p->data = num;
    p->next = NULL;

    if (head == NULL)
    {
        head = p;
        tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
}

Node* purge(Node *&head, int key)
{
    Node *ptr = head;
    Node *prev = head;
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            if (ptr == head)
            {
                Node *temp = head;
                head = head->next;
                prev = prev->next;
                ptr = ptr->next;
                delete temp;
                // ptr = ptr->next;
            }
            else
            {
                if (ptr->next != NULL)
                {
                    Node *temp = ptr;
                    prev->next = temp->next;
                    ptr = ptr->next;
                    delete temp;
                }
                else
                {
                    Node *temp = ptr;
                    ptr = prev;
                    delete temp;
                }
            }
        }
        else
        {
            if (ptr == head)
            {
                ptr = ptr->next;
            }
            else
            {
                ptr = ptr->next;
                prev = prev->next;
            }
        }
    }
     return *&head;
}

int main()
{

    Node *head = NULL, *tail = NULL;
    int num = 0;

    // build linked list backward
    cout << "input integers (-999 to end): ";
    cin >> num;
    while (num != -999)
    {
        tail_insert(head, tail, num);
        cin >> num;
    }

    linkedListTraversal(head);

    Node* tester = purge(head, 20);
    cout<<"Change"<<endl;
    cout<<"Head"<<tester->data<<endl;

    linkedListTraversal(head);

    return 0;
}
