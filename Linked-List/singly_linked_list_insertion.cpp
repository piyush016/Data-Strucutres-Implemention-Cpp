#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
class Singly_Linked_List:public Node
{
    Node *head,*tail;
    public:
        Singly_Linked_List()
        {
            head = NULL;
            tail = NULL;
        }
    void create_list();
    void insert_beg();
    void insert_end();
    void insert_after();
    void insert_before();
    void print_list();
    void total_nodes();
};
//function to create a list
void Singly_Linked_List::create_list()
{
    Node *newnode;
    newnode = new Node;
    int info;
    cout << "Enter the data of the newnode: ";
    cin >> info;
    newnode -> data = info;
    newnode -> next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    cout << "\nLinked List is created successfully";    
}
//function to insert the node in the beginning
void Singly_Linked_List::insert_beg()
{
    Node *newnode;
    newnode = new Node;
    int info;
    cout << "Enter the data of the newnode: ";
    cin >> info;
    newnode -> data = info;
    // newnode -> next = NULL;
    newnode -> next = head;
    head = newnode;
    cout << "Newnode with data "<<info<<" is added at the start";
}
//function to insert a node at the end of the list
void Singly_Linked_List::insert_end()
{
    Node *newnode;
    //temporary pointer created  to point at the starting node
    Node *ptr;
    newnode = new Node;
    int info;
    cout << "Enter the data of the newnode: ";
    cin >> info;
    newnode -> data = info;
    newnode -> next = NULL;
    ptr = head;
    while(ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }
    ptr -> next = newnode;
    cout << "Newnode with data "<< info << " inserted successfully";
}
//function to insert a node after a given node in the linked list
void Singly_Linked_List::insert_after()
{
    Node *newnode,*ptr,*preptr;
    newnode = new Node;
    ptr = head;
    preptr = ptr;
    int info,num;
    cout << "\nEnter the data of the node after which the newnode is to be inserted: ";
    cin >> num;
    cout << "Enter the data of the newnode: ";
    cin >> info;
    newnode -> data = info;
    newnode -> next = NULL;
    while(preptr -> data != num)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = newnode;
    newnode -> next = ptr;
    cout << "\n Node with data "<< info << " added.";
}
//function to insert a node before a particular node
void Singly_Linked_List::insert_before()
{
    Node *newnode,*ptr,*preptr;
    newnode = new Node;
    ptr = head;
    preptr = ptr;
    int num,info;
    cout << "Enter the data of the node before which the newnode is to be inserted: ";
    cin >> num;
    cout << "Enter the data of the newnode";
    cin >> info;
    newnode -> data = info;
    newnode -> next = NULL;
    while(ptr -> data != num)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = newnode;
    newnode -> next = ptr;
    cout << "Newnode with data  " << info << " added.";
}
//function to print the linked list:
void Singly_Linked_List::print_list()
{
    Node *ptr;
    ptr = head;
    while(ptr -> next != NULL)
    {
        cout << ptr -> data <<"  ->  ";
        ptr = ptr -> next;
    }
    cout << ptr -> data;
    cout << "\n";
}
void Singly_Linked_List::total_nodes()
{
    int count = 0;
    Node *ptr;
    ptr = head;
    while(ptr -> next != NULL)
    {
        count++;
        ptr = ptr -> next;
    }
    count++;
    cout << "The total number of nodes are: "<< count;
}
int main()
{
    //creation of object;
    Singly_Linked_List sl;
    int ch;
    while(1)
    {
        cout <<"\n**** MENU ****";
        cout <<"\n1.CREATE_LIST\n2.INSERT_BEGINNING\n3.INSERT_END\n4.INSERT_AFTER\n5.INSERT_BEFORE\n6.PRINT_LIST\n7.COUNT\n8.EXIT";
        cout <<"\nEnter the users choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:sl.create_list();
                break;
            case 2: sl.insert_beg();
                break;
            case 3:sl.insert_end();
                break;
            case 4:sl.insert_after();
                break;
            case 5:sl.insert_before();
                break;
            case 6:sl.print_list();
                break;
            case 7:sl.total_nodes();
                break;
            case 8:exit(0);
            default:cout << "Please enter a valid choice: ";
        }
    }
    return 0;
}
