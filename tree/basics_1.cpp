#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    //Constructor
    node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }


};
///

node* build_tree(node* root){
    cout<<"Enter the data: ";
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter element to left of "<<data<<endl;
    root->left=build_tree(root->left);
    cout<<"Enter element to right of "<<data<<endl;
    root->right=build_tree(root->right);
    return root;



void level_order_traversal()


}

int main(){
    node* root=NULL;

    //creating tree
    root=build_tree(root);

}