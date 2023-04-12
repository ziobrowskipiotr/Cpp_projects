#include <iostream>
using namespace std;

const int ROWS = 9;

class Board{
private:
    char board[ROWS];
public:
    void set_X(int i);
    void display();
    void set_O(int i);
    void set_board();
    bool win_check();
};

void Board::set_board(){
    for(int i = 0 ; i < ROWS; i++){
        board[i] = ' ';
    }
}

void Board::display(){
    cout << board[0] << " | "  << board[1] << " | "  << board[2] <<endl;
    cout << board[3] << " | "  << board[4] << " | "  << board[5] <<endl;
    cout << board[6] << " | "  << board[7] << " | "  << board[8] <<endl;
}

void Board::set_X(int i) {
    while(board[i-1] == 'X' || board[i-1] == 'O'){
        cout << "This place is taken! Try again!"<< endl;
        cin >> i;
    }
    board[i-1] = 'X';
    display();
}

void Board::set_O(int i) {
    while(board[i-1] == 'X' || board[i-1] == 'O'){
        cout << "This place is taken! Try again!"<< endl;
        cin >> i;
    }
    board[i-1] = 'O';
    display();
}

bool Board::win_check() {
    bool check = false;
    if((board[0] == board[1] && board[2] == board[3] && board[1] != ' ')||
       (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')||
       (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')||
       (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')||
       (board[2] == board[4] && board[4] == board[6] && board[2] != ' '))
    {
        check = true;
    }
    return check;
}

int main() {
    int i, j;
    Board board;
    board.set_board();
    for (int a = 0; a < ROWS; a++) {
        if (a % 2 == 0) {
            cout << "O's move" << endl;
            cout << "Select pole 1-9" << endl;
            cin >> i;
            board.set_O(i);
            if (board.win_check()) {
                cout << "Player O won!" << endl;
                break;
            }
        } else {
            cout << "X's move" << endl;
            cout << "Select pole 1-9" << endl;
            cin >> j;
            board.set_X(j);
            if (board.win_check()) {
                cout << "Player X won!" << endl;
                break;
            }
        }
    }
    return 0;
}