#include <iostream>
using namespace std;

void arr (int *n){
    cout<<*n<<endl;
    *n=5;
    cout<<*n<<endl;

}

int main(){
    int n=0;
    int *ptr = &n;
    arr(ptr);
    cout<<n<<endl;

}
