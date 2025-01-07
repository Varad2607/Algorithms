#include <iostream>
using namespace std;


struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data=val;
        left=right=NULL;

    }

};


// Traversal in tress
// We have 2 methods DFS and BFS
// DFS-Inorder, Pre-order, Post order
// BFS-Level order traversal


// Inorder travesal (Left->Root->Right)
void inorder_traversal(Node *root){
    if (root==NULL){
        return;
    }
    inorder_traversal(root->left);
    cout<<root->data;
    inorder_traversal(root->right);
    
}

void preorder_traversal(Node *root){
    if (root==NULL){
        return;
    }
    cout<<root->data;
    preorder_traversal(root->left);
    preorder_traversal(root->right);


}

void postorder_traversal(Node *root){
    if (root==NULL){
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data;

}


int main(){
    Node *root= new Node(1);
    root->left=new Node(2);
    root->right= new Node (3);
    inorder_traversal(root);
    preorder_traversal(root);
    postorder_traversal(root);
    
}