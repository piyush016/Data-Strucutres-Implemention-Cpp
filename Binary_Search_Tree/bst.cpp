#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *left;
        Node *right;
};
class Binary_Search_Tree:public Node
{
    
    public:
        Node *root;
        Binary_Search_Tree()
        {
            root = NULL;
        }
    void insert_node();
    void delete_node(Node *root);
    void pre_order(Node *root);
    void in_order(Node *root);
    void post_order(Node *root);
    int find_smallest(Node *root);
    int find_largest(Node *root);
};
void Binary_Search_Tree::insert_node()
{
    Node *newnode,*parentptr,*currentptr;
    int val;
    newnode = new Node;
    cout << "Enter the data of the newnode: ";
    cin >> val;
    newnode -> data = val;
    newnode -> left = NULL;
    newnode -> right = NULL;
    //When no node is present
    if(root == NULL)
    {
        root = newnode;
        root -> left = NULL;
        root -> right = NULL;
        cout << "Tree is created.";
    }
    //When root node is created
    else
    {
        parentptr = NULL;
        currentptr = root;
        while(currentptr != NULL)
        {
            parentptr = currentptr;
            if(val < currentptr -> data)
            {
                currentptr = currentptr -> left;
            }
            else
            {
                currentptr = currentptr -> right;
            }    
        }
        if(val < parentptr -> data)
        {
            parentptr -> left = newnode;
        }
        else
        {
            parentptr -> right = newnode;  
        }
        cout << "Newnode with data: "<< val << " inserted.";
    }
}
// void Binary_Search_Tree::delete_node(Node *root)
// {
//     int value;
//     cout << "Enter the data of the node that is to be deleted: ";
//     cin >> value;
//     if(root == NULL)
//     {
//         return;
//     }
//     //target node found
//     if(root -> data == value)
//     {
//         //case 1:if it is the leaf node
//         if((root -> left == NULL) && (root -> right == NULL))
//         {
//             cout << "Node with data: "<< root -> data << " is deleted";
//             root = NULL;
//         }
//     }
// }
void Binary_Search_Tree::pre_order(Node *root)
{
    cout << "PRE_ORDER TRAVERSAL IS: ";
    if(root == NULL)
    {
        return;
    }
    cout << root -> data << " ";
    pre_order(root -> left);
    pre_order(root -> right);
}
void Binary_Search_Tree::in_order(Node *root)
{
    cout << "INORDER TRAVERSAL IS: ";
    if(root == NULL)
    {
        return;
    }
    in_order(root -> left);
    cout << root -> data << " ";
    in_order(root -> right);
}
void Binary_Search_Tree::post_order(Node *root)
{
    cout << "POSTORDER TRAVERSAL IS: ";
    if(root == NULL)
    {
        return;
    }
    post_order(root -> left);
    post_order(root -> right);
    cout << root -> data << " ";
}
int Binary_Search_Tree::find_smallest(Node *root)
{
    if((root == NULL) || (root -> left == NULL))
    {
        cout << "THE SMALLEST VALUE IN THE TREE IS: " << root -> data;
    }
    else
    {
        return find_smallest(root -> left);
    }
    
}
int Binary_Search_Tree::find_largest(Node *root)
{
    if((root == NULL) || (root -> right == NULL))
    {
        cout << "THE LARGEST VALUE IN THE TREE IS: " << root -> data;
    }
    else
    {
        return find_largest(root -> right);
    }
    
}
int main()
{
    Binary_Search_Tree bst;
    int ch;
    while(1)
    {
        cout << "\n****MAIN MENU****";
        cout << "\n1.INSERT_ELEMENT\n2.DELETE_ELEMENT\n3.PRE_ORDER\n4.IN_ORDER\n5.POST_ORDER\n6.FIND_LARGEST\n7.FIND_SMALLEST\n8.EXIT";
        cout << "\nEnter the users choice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:bst.insert_node();
                break;
            case 2:bst.delete_node(bst.root);
                break;
            case 3:bst.pre_order(bst.root);
                break;
            case 4:bst.in_order(bst.root);
                break;
            case 5:bst.post_order(bst.root);
                break;
            case 6:bst.find_largest(bst.root);
                break;
            case 7:bst.find_smallest(bst.root);
                break;
            case 8:exit(0);
                break;
            default:cout << "Enter a valid option.";
        }
    }
    return 0;
}
