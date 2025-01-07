#include <iostream>
using namespace std;

int main(){
    int num=5;
    cout<<num<<endl;
    int *ptr=&num;
    cout<<*ptr;
    cout<<ptr;
}