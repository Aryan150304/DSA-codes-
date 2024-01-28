#include <iostream>
using namespace std;
class Stack
{
public:
    int *arr;
    int size;
    int top;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        this->top = -1;
    }
    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Can't insert Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        else
        {
            top--;
        }
    }
    int sizes()
    {
        return top + 1;
    }
    bool isempty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void print()
    {
        int count = top;
        while (count != -1)
        {
            cout << arr[count] << " ";
            count--;
        }
        cout << endl;
    }
    ~Stack()
    {
        delete[] arr;
    }
};
int main()
{
    cout << "This is the array implementation of stack" << endl;
    Stack st(5);
    st.push(10);
    st.print();
    st.isempty();
    st.push(20);
    st.print();
    cout << st.isempty() << endl;
    st.push(30);
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.print();
    st.pop();
    st.print();
    cout << st.isempty() << endl;
    ;
    cout << st.sizes() << endl;
    return 0;
}
// 0x600000d0d260
