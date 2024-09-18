#include <iostream>
#include <string>
using namespace std;

class Teacher{
    //properties/attributes
    private:
    double salary;
    public:
    string name;
    string dept;
    string subject;
    
    //methods/member functions

    void changeDept(string newDept){
        dept=newDept;
    }

    //setter
    void setSalary(double s){
        salary =s;

    } 
    //getter
    double getSalary (){
        return salary;

    }


};

int main(){
    Teacher t1;
    t1.name="varad";
    t1.subject="cpp";
    t1.salary=12;



    return 0;

}