#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define max 10  
class Queue
{
    int front,rear;
    public:
        int queue[max]; 
        Queue()
        {
            front = -1;
            rear = -1;
        }
    void insert_element();
    void delete_element();
    void peek();
    void display();
};
void Queue::insert_element()
{
    int val;
    cout << "Enter the element: ";
    cin >> val;
    if(rear == max - 1)
    {
        cout << "Queue is full";
    }
    else
    {
        if((front == -1) && (rear == -1))
        {
            front  =  0;
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
        queue[rear] = val;
        cout << "Element entered in the queue.";
    }
    
}
void Queue::delete_element()
{
    int value;
    if((front == -1) && (front > rear))
    {
        cout << "Queue Underflow.";
    }
    else
    {
        value = queue[front];
        front = front + 1;
        cout << "Element "<< value << " deleted.";
    }
    
}
void Queue::peek()
{
    if((front == -1) && (front > rear))
    {
        cout << "Nothing to display.";
    }
    else
    {
        cout << "Element at front are: "<<queue[front];
    }
}
void Queue::display()
{
    if(front == -1)
    {
        cout << "Nothing to display.";
    }
    else
    {
        cout << "QUEUE ELEMENTS ARE: ";
        for(int i = front ; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
    }
    
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
            cout << "Enter a valid choice: ";
        }
    }
    return 0;
}
