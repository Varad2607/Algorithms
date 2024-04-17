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
Node* build_tree(Node* root){
    cout<<"Enter the number in root: ";
    int data;
    cin>>data;
    root=new Node(data);

    if(data==-1){
        return NULL;
    }
    cout<<"Enter elements to left";
    root->left=build_tree(root->left);
    cout<<"Enter elements to left: ";
    root->right=build_tree(root->right);
    return root;

    i

}

int height(Node *root){
    if(root==NULL){
        return 0;
    }
    else{
        return max(height(root->left),height(root->right))+1;

    }

    
}

int main(){
    //
    Node* root=NULL;
    root=build_tree(root);


}