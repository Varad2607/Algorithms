#include <iostream>
#include <string>
using namespace std;

class draw_board{
    public:
    void display_board(char board[3][3]){
        cout<<"----------------\n";
        for(int i=0;i<3;i++){
            
            cout<<"| ";
            for(int j=0;j<3;j++){
                cout<<board[i][j]<<" | ";
            
            }
            cout << "\n-------------\n";
           
        }
    }

};

class winner_criteria{
    public: 
    bool match_winner(char board [3][3])

};

int main(){
    char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    draw_board show;
    show.display_board(board);


}