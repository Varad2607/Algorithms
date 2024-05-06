#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
Node * build_tree(Node* root){
    cout<<"Enter the data for the node: "<<endl;
    int d;
    cin>>d;
    root=new Node(d);
    if(d==-1){
        return NULL;
    }
    cout<<"Enter the left child of "<<d<<endl;
    root->left=build_tree(root->left);
    cout<<"Enter the right child of "<<d<<endl;
    root->right=build_tree(root->right);
    return root;


    

}

int main(){
    //Create a blanck node
    Node* root=NULL;

    //Build the tree by adding data to the nodes
    root=build_tree(root);


}