#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }

};

node* build_tree(node* root){
cout<<"Enter the number in root: ";
int data;
cin>>data;
root=new node(data);
if(data==-1){
    return NULL;
}
cout<<"Enter element to left: "<<endl;
root->left=build_tree(root->left);
cout<<"Enter element to right"<<endl;
root->right=build_tree(root->right);
return root;

}

int main(){
    node* root=NULL;
    root=build_tree(root);


}