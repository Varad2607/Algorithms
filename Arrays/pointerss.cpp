#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main(){
    unique_ptr<int> ptr1=make_unique<int>(10);
    unique_ptr<int> ptr2=move(ptr1);
    cout<<*ptr2<<endl;
    return 0;

    
}
