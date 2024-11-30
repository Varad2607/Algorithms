#include <iostream>
using namespace std;

int factorial(int n){
    int c;
    if (n==0){
        return 1;
    }

    c=n*factorial(n-1);

    return c;

}


int main(){
    int n=4;
    cout<<factorial(n);
}