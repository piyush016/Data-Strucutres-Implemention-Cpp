// To demonstrate how stack works in Array using classc.

#include <iostream>
using namespace std;

#define MAX_SIZE 101

class Stack
{
private:
    int A[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void Push(int x)
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "ERROR: STACK OVERFLOW";
            return;
        }
        A[++top] = x;
    }

    void Pop()
    {
        if (top == -1)
        {
            cout << "ERROR: NO ELEMENT IN STACK";
            return;
        }
        --top;

    }

    int Top()
    {
        return A[top];
    }

    int isEmpty()
    {
        if (top == -1) return 1;
        return 0;
    }

    void Print()
    {
        int i;
        cout << "Stack: ";
        for (i=0; i<=top; i++)
            cout << A[i] << " ";
        cout << endl;
    }

};


int main()
{
    Stack S;

    S.Push(2); S.Print();
    S.Push(5); S.Print();
    S.Push(10); S.Print();
    S.Push(12); S.Print();

    S.Pop(); S.Print();
    S.Pop(); S.Print();

    S.Push(17); S.Print();

}