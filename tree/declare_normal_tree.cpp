#include <iostream>
#include <queue>
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
 void level_order_traversal(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if (temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
         

    }

 }





int main(){
    //Create a blanck node
    Node* root=NULL;

    //Build the tree by adding data to the nodes
    root=build_tree(root);

    //Level order traversal of the tree
    // 1 3 7 -1 -1  11 -1 -1 5 17 -1 -1 -1 
   \


}