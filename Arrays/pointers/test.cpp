#include <iostream>
using namespace std;


//If I want to send values to a function and change them, 
// I can use pointers if using void function and if using int function, I can return the value and store it in a variable.
// I can also use reference variables to change the value of a variable in a function.


// void arr (int *n){
//     cout<<*n<<endl;
//     *n=5;
//     cout<<*n<<endl;

// }

// int main(){
//     int n=0;
//     int *ptr = &n;
//     arr(ptr);
//     cout<<n<<endl;

// }

int arr (int n){
    // cout<<n<<endl;
    n=5;
    // cout<<n<<endl;

    return n;

}

int main(){
    int n=0;
    int var=arr(n);
    cout<<var<<endl;
    cout<<n<<endl;

}



