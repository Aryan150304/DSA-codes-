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
        cout << "The node with the data " << this->data << " has been deleted" << endl;
        this->next = NULL;
    }
};

class Stack
{
public:
    int size;
    int top;
    Node *head;
    Node *tail;
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->head = NULL;
        this->tail = NULL;
    }
    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Cant insert Stack overflow" << endl;
            return;
        }
        top++;
        Node *temp = new Node(data);
        if (this->head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        temp->next = head;
        head = temp;
    }

    void print()
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Can't delete as stack is underflow" << endl;
        }
        top--;
        Node *tbd = head;
        if (head->next != NULL)
        {
            head = head->next;
        }
        else
        {
            head = NULL;
            tail = NULL;
        }
        delete tbd;
    }
};
int main()
{
    cout << "This is the implemenation of stack using linked lists" << endl;
    Stack st(5);
    st.push(10);
    st.print();
    // st.isempty();
    st.push(20);
    st.print();
    // cout << st.isempty() << endl;
    st.push(30);
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.print();
    // cout << st.isempty() << endl;
    // cout << st.sizes() << endl;

    return 0;
}
