#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
        Node *prev;
};
class Doubly_Linked_List_insertion:public Node
{
    Node *head;
    public:
        Doubly_Linked_List_insertion()
        {
            head = NULL;
        }
    void create_list();
    void insert_beg();
    void insert_end();
    void insert_before();
    void insert_after();
    void print_list();
};
void Doubly_Linked_List_insertion::create_list()
{
    Node *newnode;
    newnode = new Node;
    int info;
    cout << "Enter the data of the newnode: ";
    cin >> info;
    newnode -> data = info;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    if(head == NULL)
    {
        head = newnode;
    }
    cout << "Linked List created successfully";
}
void Doubly_Linked_List_insertion::insert_beg()
{
    Node *newnode,*ptr;
    newnode = new Node;
    int info;
    cout << "Enter the data of the newnode: ";
    cin >> info;
    newnode -> data = info;
    newnode -> prev = NULL;
    newnode -> next = head;
    head -> prev = newnode;
    head = newnode;
    cout << " Newnode with data " << info << " inserted at the beginnning.";    
}
void Doubly_Linked_List_insertion::insert_end()
{
    Node *newnode,*ptr;
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
    newnode -> prev = ptr;
    cout << "Newnode with data " << info << " inserted.";
}
void Doubly_Linked_List_insertion::insert_before()
{
    Node *newnode,*ptr;
    newnode = new Node;
    int info,num;
    cout << "Enter the data of the node after which the newnode is to be inserted: ";
    cin >> num;
    cout << "Enter the data of the newnode: ";
    cin >> info;
    newnode -> data = info;
    ptr = head;
    while(ptr -> data != num)
    {
        ptr = ptr -> next;
    }
    newnode -> next = ptr;
    newnode -> prev = ptr -> prev;
    ptr -> prev -> next = newnode;
    ptr -> prev = newnode;
    cout << "Newnode with data " << info << " inserted.";
}
void Doubly_Linked_List_insertion::insert_after()
{
    Node *newnode,*ptr;
    newnode = new Node;
    int info,num;
    cout << "Enter the data of the node after which the newnode is to be inserted: ";
    cin >> num;
    cout << "Enter the data of the newnode: ";
    cin >> info;
    newnode -> data = info;
    ptr = head;
    while(ptr -> data != num)
    {
        ptr = ptr -> next;
    }
    newnode -> next = ptr -> next;
    newnode -> prev = ptr;
    ptr -> next = newnode;
    ptr -> next -> prev = newnode;
    cout << "Newnode with data "<< info <<" inserted.";
}
void Doubly_Linked_List_insertion::print_list()
{
    Node *ptr;
    ptr = head;
    while(ptr -> next != NULL)
    {
        cout << ptr -> data << " -> ";
        ptr = ptr -> next;
    }
    cout << ptr -> data;
}
int main()
{
    Doubly_Linked_List_insertion dl;
    int ch;
    while(1)
    {
        cout << "\n****MAIN MENU****";
        cout << "\n1.CREATE_LIST\n2.INSERT_BEG\n3.INSERT_END\n4.INSERT_BEFORE\n5.INSERT_AFTER\n6.PRINT_LIST\n7.EXIT";
        cout << "\nEnter the users choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:dl.create_list();
                break;
            case 2:dl.insert_beg();
                break;
            case 3:dl.insert_end();
                break;
            case 4:dl.insert_before();
                break;
            case 5:dl.insert_after();
                break;
            case 6:dl.print_list();
                break;
            case 7:exit(0);
                break;
            default:cout << "\nEnter a valid choice: ";
        }
    }
    return 0;
} 