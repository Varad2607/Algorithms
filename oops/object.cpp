#include <iostream>
using namespace std;

class Hero{

    private:
        int health;
    public:

    Hero (){
        cout<<"SImple"<<endl;
    }
        
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

    Hero onkar;





}

