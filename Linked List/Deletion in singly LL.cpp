#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        this->next = NULL;
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
    head = newNode;
}

void insertattail(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    newNode->next = NULL;
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
    temp->next = newNode;
}

void deletes(Node *&head, Node *&tail, int pos)
{
    Node *temp = head;
    if (pos == 1)
    {
        head = temp->next;
        delete temp;
        return;
    }
    Node *prev;
    for (int i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        prev->next = NULL;
        tail = prev;
        delete temp;
    }
    prev->next = temp->next;
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
    // 50 20 10 30
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
    // 20 10 30

    return 0;
}
