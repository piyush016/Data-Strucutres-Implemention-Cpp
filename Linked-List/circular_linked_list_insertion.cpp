//Note:Insertion in a circular linked list after a given node and before a given node is as same as singly linked list
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
class Circular_Linked_List_ins:public Node
{
    Node *head,*tail;
    public:
        Circular_Linked_List_ins()
        {
            head = NULL;
            tail = NULL;
        }
    void create_list();
    void insert_beg();
    void insert_end();
    void print_list();  
};
void Circular_Linked_List_ins::create_list()
{
    Node *newnode;
    newnode = new Node;
    int info;
    cout << "Enter the data of the newnode: ";
    cin >> info;
    newnode -> data = info;
    newnode -> next = NULL;
    if(head == NULL)
    {
        head = newnode;
        newnode -> next = head;
    }
    cout << "Linked List created successfully: ";
}
void Circular_Linked_List_ins::insert_beg()
{
    Node *newnode,*ptr;
    newnode = new Node;
    int info;
    cout << "Enter the data of the newnode: ";
    cin >> info;
    newnode -> data = info;
    ptr = head;
    while(ptr -> next != head)
    {
        ptr = ptr -> next;
    }
    newnode -> next = head; 
    ptr -> next = newnode;
    head = newnode;
    cout << "Newnode  with data "<< info << " inserted.";
}
void Circular_Linked_List_ins::insert_end()
{
    Node *newnode,*ptr;
    newnode = new Node;
    int info;
    cout << "Enter the data of the newnode: ";
    cin >> info;
    newnode -> data = info;
    newnode -> next = head;
    ptr = head;
    while(ptr -> next != head)
    {
        ptr = ptr -> next;
    }
    ptr -> next = newnode;
    cout << "Newnode with data "<< info << " inserted";
}
void Circular_Linked_List_ins::print_list()
{
    Node *ptr;
    ptr = head;
    while(ptr -> next != head)
    {
        cout << ptr -> data << " -> ";
        ptr = ptr -> next;
    }
    cout << ptr -> data;
}
int main()
{
    Circular_Linked_List_ins cl;
    int ch;
    while(1)
    {
        cout << "\n****MAIN MENU****";
        cout << "\n1.CREATE_LIST\n2.INSERT_BEG\n3.INSERT_END\n4.PRINT_LIST\n5.EXIT";
        cout << "\nEnter users choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:cl.create_list();
                break;
            case 2:cl.insert_beg();
                break;
            case 3:cl.insert_end();
                break;
            case 4:cl.print_list();
                break;
            case 5:exit(0);
                break;
            default:cout << "\nEnter any valid choice: ";
        }
    }
    return 0;
}