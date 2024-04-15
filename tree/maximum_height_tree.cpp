#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
//change
    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
   



    




};
 Node* build_tree(Node* root){
        cout<<"Enter the data for: "<<endl;
        int data;
        cin>>data;
        root=new Node(data);
        if (data==-1){
            return NULL;

        }
        cout<<"Enter data in left: "<<endl;
        root->left=build_tree(root->left);
        cout<<"Enter for right data: "<<endl;
        root->right=build_tree(root->right);
        return root;

        }
    void level_order_traversal(Node* root){
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* temp=q.front();
            cout<<temp->data<<" ";
            q.pop();
            if(temp=NULL){
                cout<<endl;
                if (!q.empty()){
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




int main(){
    Node* root=NULL;
    root=build_tree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"printing level order traversal"<<endl;
    level_order_traversal(root);
    return 0;
}