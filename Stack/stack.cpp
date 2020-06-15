#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define max 5
class Stack
{
    int top;
    public:
        int stack[max];
        Stack()
        {
            top = -1;
        }
    void push();
    void pop();
    void peep();
    void display();
};
void Stack::push()
{
    int data;
    cout << "Enter the data to be pushed: ";
    cin >> data;
    if(top == max - 1)
    {
        cout << "Maximum capacity reached.";
    }
    else
    {
        top++;
        stack[top] = data;
        cout << "Value "<< data << " pushed.";
    }    
}
void Stack::pop()
{
    if(top == -1)
    {
        cout << "Stack underflow"<<endl;
    }
    else
    {
        cout << "Element popped is: "<<stack[top];
        top--;
    }
    
}
void Stack::peep()
{
    if(top == -1)
    {
        cout << "Nothing to display: ";
    }
    else
    {
        cout << "Element at the top is: "<< stack[top];
    }
    
}
void Stack::display()
{
    if(top == -1)
    {
        cout << "Nothing to display.";
    }
    else
    {
        for(int i = top;i >=0;i--)
        {
            cout << stack[i] << "\n";
        }
    }
    
}
int main()
{
    Stack s;
    int ch;
    while(1)
    {
        cout << "\n****MAIN MENU****";
        cout << "\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT";
        cout << "\nEnter the users choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:s.push();
                break;
            case 2:s.pop();
                break;
            case 3:s.peep();
                break;
            case 4:s.display();
                break;
            case 5:exit(0);
                break;
            defaut:cout << "\nEnter a valid choice: ";
        }
    }
    return 0;
}
