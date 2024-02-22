#include <iostream>
using namespace std;


//In cpp in class all members are private by default
class student{
    public:
    string name;
    int age;
    bool gender;

    student(){
        cout<<"Default constructor"<<endl;
    }


    //Constructor
    student(string s){
        name = s;
    }
    void getName(){
        cout<<name<<endl;
    }

};



int main(){
    // student arr[3];
    // for(int i=0;i<3;i++){
    //     cin>>arr[i].name;
    //     cin>>arr[i].age;
    //     cin>>arr[i].gender;
    // }

    // for(int i=0;i<3;i++){
    //     arr[i].printInfo();
        

    // }
    student a("Rahul");
    a.getName

    return 0;
}