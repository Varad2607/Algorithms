#include <iostream>
using namespace std;

class hero{

    private:
        int health;
    public:
        // properties
        char name[100];
        char level;

        void print(){
            cout<<level<<endl;

        }

        int getHealth(){
            return health;
        }

        char getLevel(){
            return level;

        }

        void setHealth(int h){
            health=h;
        }
        void setlevel(char ch){
            level=ch;
        }





};

int main(){



    //created object of hero
    hero h1;



}

//getter
//setter
