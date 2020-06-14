#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *prev;
        Node *next;
};
class Doubly_Linked_List_del:public Node
{

    Node *head;
    public:
        Doubly_Linked_List_del()
        {
            head = NULL;
        }
    void create_list();
    void insert_end();
    void delete_beg();
    void delete_end();
    void delete_before();
    void delete_after();
    void print_list();
};
void Doubly_Linked_List_del::create_list()
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
void Doubly_Linked_List_del::insert_end()
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
void Doubly_Linked_List_del::delete_beg()
{
    Node *ptr;
    ptr = head;
    head = head -> next;
    head -> prev = NULL;
    cout << "Node with data " << ptr -> data << " is deleted.";
    free(ptr);
}
void Doubly_Linked_List_del::delete_end()
{
    Node *ptr;
    ptr = head;
    while(ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }
    ptr -> prev -> next = NULL;
    cout << "Node with data " << ptr -> data << " is deleted.";
    free(ptr);
}
void Doubly_Linked_List_del::delete_before()
{
    Node *ptr,*temp;
    int num;
    cout << "Enter the data of the node whose before node is to be deleted: ";
    cin >> num;
    ptr = head;
    while(ptr -> data != num)
    {
        ptr = ptr -> next; 
    }
    temp = ptr -> prev;
    temp -> prev -> next = ptr;
    ptr -> prev = temp -> prev;
    cout << "Node with data " << temp -> data << " is deleted."; 
    free(temp);
}
void Doubly_Linked_List_del::delete_after()
{
    Node *ptr,*temp;
    ptr = head;
    int num;
    cout << "Enter the data of the node whose afternode is to be deleted: ";
    cin >> num;
    while(ptr -> data != num)
    {
        ptr = ptr -> next;
    }
    temp = ptr -> next;
    ptr -> next = temp -> next;
    temp -> next -> prev = ptr;
    cout << "Node with data " << temp -> data << " is deleted.";
    free(temp);
}
void Doubly_Linked_List_del::print_list()
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
    Doubly_Linked_List_del dl;
    int ch;
    while(1)
    {
        cout << "\n****MAIN MENU****";
        cout << "\n1.CREATE_LIST\n2.INSERT_END\n3.DELETE_BEG\n4.DELETE_END\n5.DELETE_BEFORE\n6.DELETE_AFTER\n7.PRINT_LIST\n8.EXIT";
        cout << "\nEnter users choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:dl.create_list();
                break;
            case 2:dl.insert_end();
                break;
            case 3:dl.delete_beg();
                break;
            case 4:dl.delete_end();
                break;
            case 5:dl.delete_before();
                break;
            case 6:dl.delete_after();
                break;
            case 7:dl.print_list();
                break;
            case 8:exit(0);
                break;
            default:cout << "Enter valid choice.";
        }
    }
    return 0;
}