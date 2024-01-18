// Insertion and deletion in doubly linked list 

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        this->next = NULL;
        this->prev = NULL;
        cout << "Node with the data " << this->data << " has been deleted" << endl;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertathead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertattail(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    newNode->next = NULL;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void insertatmiddle(Node *&tail, Node *&head, int data, int pos)
{
    if (pos == 1)
    {
        insertathead(head, data);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        insertattail(tail, data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deletes(Node *&head, Node *&tail, int pos)
{
    Node *temp = head;
    if (pos == 1)
    {
        temp->next->prev = NULL;
        head = temp->next;
        delete temp;
        return;
    }
    Node *prevs;
    for (int i = 1; i < pos; i++)
    {
        prevs = temp;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        prevs->next = NULL;
        tail = prevs;
        delete temp;
        return;
    }

    prevs->next = temp->next;
    temp->next->prev = prevs;
    delete temp;
}

int main()
{
    Node *newNode = new Node(10);
    Node *head = newNode;
    Node *tail = newNode;
    print(head);
    // 10
    // code for insertion
    insertathead(head, 20);
    print(head);
    // 20 10
    insertattail(tail, 30);
    print(head);
    // 20 10 30
    insertatmiddle(tail, head, 50, 1);
    print(head);
    // // 50 20 10 30
    insertatmiddle(tail, head, 500, 5);
    print(head);
    // 50 20 10 30 500
    insertatmiddle(tail, head, 200, 3);
    // 50 20 200 10 30 500
    print(head);

    deletes(head, tail, 3);
    // 50 20 10 30 500
    print(head);
    deletes(head, tail, 1);
    print(head);
    // 20 10 30 500
    deletes(head, tail, 4);
    print(head);
    cout << tail->data << endl;
    // 20 10 30

    return 0;
}
