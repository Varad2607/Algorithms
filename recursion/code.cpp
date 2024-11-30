#include <iostream>
using namespace std;

void printnumbers(int n){
    if (n==1){
        cout<<"1"<<endl;
        return;
    }

    cout<<n<<" "<<endl;
    printnumbers(n-1);
    
}

int main(){

    printnumbers(70);

}