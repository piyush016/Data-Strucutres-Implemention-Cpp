//Implementing stack using linked list.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *next; 
};
class Stack:public Node
{
    Node *top;
    public:
        Stack()
        {
            top = NULL;
        }
    void push();
    void pop();
    void peek();
    void display();
};
void Stack::push()
{
    Node *newnode;
    newnode = new Node;
    int info;
    cout << "Enter the data of the newnode: ";
    cin >> info;
    newnode -> data = info;
    if(top == NULL)
    {
        newnode -> next = NULL;
        top = newnode;
    }
    else
    {
        newnode -> next = top;
        top = newnode;
    }
    
}
void Stack::pop()
{
    Node *ptr;
    ptr = top;
    top = top -> next;
    cout << "Node with info "<< ptr->data<< " is deleted";
    free(ptr);
}
void Stack::display()
{
    Node *ptr;
    ptr = top;
    if(top == NULL)
    {
        cout << "Stack is empty.";
    }
    else
    {
        while(ptr -> next != NULL)
        {
            cout << ptr -> data << " -> ";
            ptr = ptr -> next;
        }
        cout << ptr -> data;
    }
    
}
int main()
{
    Stack s;
    int ch;
    while(1)
    {
        cout << "\n****MAIN MENU****";
        cout << "\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT";
        cout << "\nEnter the users choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:s.push();
                break;
            case 2:s.pop();
                break;
            case 3:s.display();
                break;
            case 4:exit(0);
        }
    }
    return 0;
}