#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main(){
    //unique pointer
    unique_ptr<int> ptr1=make_unique<int>(10);
    unique_ptr<int> ptr2=move(ptr1);
    cout<<*ptr2<<endl;


    //Shared Pointer
    shared_ptr<int> ptr_shared=make_shared<int>(20);
    shared_ptr<int> ptr_shared2=ptr_shared;
    cout<<*ptr_shared<<endl;
    cout<<*ptr_shared2<<endl;
    return 0;


}
