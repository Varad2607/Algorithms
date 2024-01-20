#include <iostream>
#include <vector>
#include <stack>
using namespace std;
////

void daily_temp(int n,int temp[],int ans[]){
    stack<int> s;
    s.push(0);
    for(int i=1;i<n;i++){
        while(!s.empty() && temp[i]>temp[s.top()]){
            ans[s.top()]=i-s.top();
            s.pop();
        }
        s.push(i);
    }
    
   
}

int main(){
    int n;
    cout<<"Enter number of elements in array temp";
    cin>>n;
    int temp[n];
    for(int i=0;i<n;i++){
        cin>>temp[i];

    }
    int ans[n];
    for(int i=0;i<n;i++){
        ans[i]=0;
    }
    daily_temp(n,temp,ans);
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
}