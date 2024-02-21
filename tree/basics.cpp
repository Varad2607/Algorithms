#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this->data = d; 
        this->left = NULL;
        this->right = NULL;
    }

};

node* buildTree(node* root){
    cout<<"Enter data"<<endl;
    int d;
    cin>>d;
    root = new node(d);
    if(d==-1){
        return NULL;
    }
    cout<<"Enter left child of "<<d<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter right child of "<<d<<endl;
    root->right = buildTree(root->right);
    return root;

}

//Create a tree
int main(){
    node* root=NULL;

    // creating a tree
    root=buildTree(root);{

    }

    

    return 0;
    

    
}