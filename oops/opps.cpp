#include <iostream>
using namespace std;


//In cpp in class all members are private by default
class student{
    public:
    string name;
    int age;
    bool gender;

};



int main(){
    student a;
    a.name = "Rahul";
    a.age =20;
    a.gender=1;


    return 0;
}