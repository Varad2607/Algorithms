#include <iostream>
#include <queue>
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


//Level order traversal

void levelorder_traversal(Node *root){
    // Add the root of the tree in queue data structure
    // use a while loop and that loop will go until the queue is empty
    // if it is Null found then give space and print it
    // Add Null again
    // if not null 
    // add root.left
    // add root.right
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()){
        Node* current_node=q.front();
        q.pop();
        if(current_node==nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
            
        }
        else{
            cout<<current_node->data<<" ";

            if (current_node->left!=nullptr){
                q.push(current_node->left);
            }
            if (current_node->right!=nullptr){
                q.push(current_node->right)l;
            }


                
            }


    }




       

}

int main(){
    Node *root= new Node(1);
    root->left=new Node(2);
    root->right= new Node (3);
    inorder_traversal(root);
    preorder_traversal(root);
    postorder_traversal(root);
    levelorder_traversal(root);
    
}