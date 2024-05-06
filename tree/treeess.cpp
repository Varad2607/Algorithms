#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;


    Node (int val){
    this->data=val;
    this->left=NULL;
    this->right=NULL;
    }
};

Node* build_tree(Node* root){
    cout<<"Enter the number you want: ";
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"ENter element to the left: ";
    root->left=build_tree(root->left);
    cout<<"ENter in right";
    root->right=build_tree(root->right);
}


int main(){
    Node*root=NULL;
    root=build_tree(root);


}