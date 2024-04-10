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

    Node* build_tree(Node* root){
        cout<<"Enter the number in the root: ";
        int data;
        cin>>data;
        root=new Node(data);
        if(data==-1){
            return NULL;

        }
        cout<<"Enter element to left: "<<endl;
        root->left=build_tree(root->left);
        cout<<"Enter element to right: "<<endl;
        root->right=build_tree(root->right);
        return root;



    }




};


int main(){
    Node* root=NULL;
    Node builder(0);
    root=builder.build_tree(root);


}
