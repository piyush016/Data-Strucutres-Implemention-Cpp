#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
};
class Singly_Linked_List_del:public Node
{
    Node *head,*tail;
    public:
        Singly_Linked_List_del()
        {
            head = NULL;
            tail = NULL;
        }
    void create_list();
    void insert_end();
    void delete_beg();
    void delete_end();
    void delete_after();
    void print_list();
};
void Singly_Linked_List_del::create_list()
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
    }
    cout << "Linked List created successfully";
}
void Singly_Linked_List_del::insert_end()
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
    cout << "Node with data "<< info <<" added.";
}
void Singly_Linked_List_del::delete_beg()
{
    Node *ptr;
    ptr = head;
    head = head -> next;
    cout << "Node with data " << ptr -> data << " is deleted";
    free(ptr);   
}
void Singly_Linked_List_del::delete_end()
{
    Node *ptr,*preptr;
    ptr = head;
    preptr = ptr;
    while(ptr -> next != NULL)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    preptr -> next = NULL;
    cout << "Node with data " << ptr -> data <<" is deleted.";
    free(ptr);
}
void Singly_Linked_List_del::delete_after()
{
    Node *ptr,*preptr,*temp;
    int num;
    cout << "Enter the data of the node whose afternode is to be deleted: ";
    cin >> num;
    ptr = head;
    preptr = ptr;
    while(preptr -> data != num)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }
    temp = ptr;
    preptr -> next = ptr -> next;
    cout << "Node with data "<< temp -> data << " is deleted";
    free(temp);
}
void Singly_Linked_List_del::print_list()
{
    Node *ptr;
    ptr = head;
    while (ptr -> next != NULL)
    {
        cout << ptr -> data << " -> ";
        ptr = ptr -> next;
    }
    cout << ptr -> data;
}
int main()
{
    Singly_Linked_List_del sl;
    int ch;
    while(1)
    {
        cout << "\n****MAIN MENU****";
        cout << "\n1.CREATE_LIST\n2.INSERT_END\n3.DELETE_BEG\n4.DELETE_END\n5.DELETE_AFTER\n6.PRINT_LIST\n7.EXIT";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:sl.create_list();
                break;
            case 2:sl.insert_end();
                break;
            case 3:sl.delete_beg();
                break;
            case 4:sl.delete_end();
                break;
            case 5:sl.delete_after();
                break;
            case 6:sl.print_list();
                break;
            case 7:exit(0);
                break;
            default:cout << "Enter a valid choice :";
        }
    }
    return 0;
}