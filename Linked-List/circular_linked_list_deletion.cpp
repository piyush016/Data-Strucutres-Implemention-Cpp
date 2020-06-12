//Deletion after a given node or before a given node in a circular linked list is as same as in Singly Linked List
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
class Circular_Linked_List_del:public Node
{
    Node *head,*tail;
    public:
        Circular_Linked_List_del()
        {
            head = NULL;
            tail = NULL;
        }
    void create_list();
    void insert_end();
    void delete_beg();
    void delete_end();
    void print_list();
};
void Circular_Linked_List_del::create_list()
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
    cout << "Linked List created successfully.";
}
void Circular_Linked_List_del::insert_end()
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
void Circular_Linked_List_del::delete_beg()
{
    Node *ptr;
    ptr = head;
    while(ptr -> next != head)
    {
        ptr = ptr -> next;
    }
    ptr -> next = head -> next;
    cout << "Node with data "<< head -> data << " is deleted";
    free(head);
    head = ptr -> next;
}
void Circular_Linked_List_del::delete_end()
{
    Node *ptr,*preptr;
    ptr = head;
    preptr = ptr;
    while(ptr -> next != head)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = head;
    cout << "Node with data: "<< ptr -> data <<" is deleted";
    free(ptr);
}
void Circular_Linked_List_del::print_list()
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
    Circular_Linked_List_del cl;
    int ch;
    while(1)
    {
        cout << "\n****MAIN MENU****";
        cout << "\n1.CREATE_LIST\n2.INSERT_END\n3.DELETE_BEG\n4.DELETE_END\n5.PRINT_LIST\n6.EXIT\n";
        cout << "Enter the users choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:cl.create_list();
                break;
            case 2:cl.insert_end();
                break;
            case 3:cl.delete_beg();
                break;
            case 4:cl.delete_end();
                break;
            case 5:cl.print_list();
                break;
            case 6:exit(0);
                break;
            default:cout << "\nEnter a valid choice: ";
        }
    }
    return 0;
}
