#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
class Queue:public Node
{
    Node *front,*rear;
    public:
        Queue()
        {
            front = NULL;
            rear = NULL;
        }
    void insert_element();
    void delete_element();
    void peek();
    void display();
};
void Queue::insert_element()
{
    Node *newnode;
    newnode = new Node;
    int val;
    cout << "Enter the data of the node: ";
    cin >> val;
    newnode -> data = val;
    if((front == NULL) && (rear == NULL))
    {
        front = rear = newnode;
        front -> next = rear -> next = NULL;
    }
    else
    {
        rear -> next = newnode;
        rear = newnode;
        rear -> next = NULL; 
    }
    cout << "Data with value "<< val << " inserted.";
    
}
void Queue::delete_element()
{
    Node *ptr;
    if(front  == NULL)
    {
        cout << "QUEUE UNDERFLOW.";
    }
    else
    {
        ptr = front;
        front = front -> next;
        cout << "Node with data: " << ptr -> data << " is deleted.";
        free(ptr);
    }
    
}
void Queue::peek()
{
    if(front == NULL)
    {
        cout << "NOTHING TO DISPLAY: ";
    }
    else
    {
        cout << "ELEMENT IS: " << front -> data;
    }
    
}
void Queue::display()
{
    Node *ptr;
    ptr = front;
    cout << "\nQUEUE ELEMENTS ARE: ";
    while(ptr != rear)
    {
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    cout << ptr -> data;
}
int main()
{
    Queue q;
    int ch;
    while(1)
    {
        cout << "\n****MAIN MENU****";
        cout << "\n1.INSERT_ELEMENT\n2.DELETE_ELEMENT\n3.PEEK_ELEMENT\n4.DISPLAY\n5.EXIT\n";
        cout << "Enter the users choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:q.insert_element();
                break;
            case 2:q.delete_element();
                break;
            case 3:q.peek();
                break;
            case 4:q.display();
                break;
            case 5:exit(0);
                break;
            default:cout << "Enter a valid option: ";
        }
    }
    return 0;
}