#include <iostream>
#include<queue>
using namespace std;
// 4 methods of tree traversal
/////
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
    cout<<"Enter the data number: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    //base case
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the left of :"<<data<<endl;
    root->left=build_tree(root->left);
    cout<<"Enter the right of :"<<data<<endl;
    root->right=build_tree(root->right);
    return root;

} 

void level_order_traversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty ()){
                q.push(NULL);

            }
            
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
            q.push(temp->left);
        }
            if(temp->right){
            q.push(temp->right);
        }
        }

       
    }

}
//Inorder traversal(LNR)
void inorder_travel(node* root){
    //base case
    if(root==NULL){
        return;
    }
    inorder_travel(root->left);
    cout<<root->data<<" ";
    inorder_travel(root->right);
}
//[reorder(NLR)
void preorder_travel(node* root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder_travel(root->left);
    preorder_travel(root->right);

}

//Postorder traversal(LRN)
void postorder_travel(node* root){
    //base case
    if(root==NULL){
        return;
    }
    postorder_travel(root->left);
    postorder_travel(root->right);
    cout<<root->data<<" ";
} 


node* build_from_level_order(node* root){
    
}

int main(){
    node* root=NULL;
    root=build_tree(root); 
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    level_order_traversal(root);
    cout<<endl;
    inorder_travel(root);
    cout<<endl;
    preorder_travel(root);
    cout<<endl;
    postorder_travel(root);
    return 0;


     

}