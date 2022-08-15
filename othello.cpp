#include<bits/stdc++.h>
using namespace std;

//命名規則
//変数　先頭小文字
//関数　先頭大文字
//定数　全て大文字
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
struct Board{
    const int board_size ;
    vector<vector<int> > board;
    int count_black, count_white;
    

    Board():board_size(10),board(10, vector<int> (10,-1)){
        for(int i = 1; i <= 8; i++){
            for(int j = 1; j <= 8; j++){
                board[i][j] = 0;
            }
        }
        board[4][4] = 1;
        board[5][5] = 1;
        board[4][5] = 2;
        board[5][4] = 2;

        count_black = 2;
        count_white = 2;
    }

    void PrintBoard(){
        for(int i = 0; i < board_size; i++){
            for(int j = 0; j < board_size; j++){
                if(board[i][j] == -1){
                    if(i == 0 && j >= 1 && j <= 8)cout << j;
                    else if(j == 0 && i >= 1 && i <= 8)cout << i;
                    else cout << '$';
                }else if(board[i][j] == 1){
                    cout << 'x';
                }else if(board[i][j] == 2){
                    cout << 'o';
                }else{
                    cout << '.';
                }
            }
            cout << endl;
        }
    }

    bool is_placable(int id, int i, int j){
        if(board[i][j] != 0)return 0;
        for(int k = 0; k < 8; k++){
            int x = i + dx[k], y = j + dy[k];
            int cnt = 0;
            bool end = 0;
            while(x >= 1 && x <= 8 && y >= 1 && y <= 8 && board[x][y] >= 1){
                if(board[x][y] == id)end = 1;
                else cnt++;
                x += dx[k], y += dy[k];
            }
            if(cnt >= 1 && end == 1)return 1;
        }
        return 0;
    }

    void place(int id, int i, int j){
        board[i][j] = id;
        if(id == 1)count_black++;
        else count_white++;
        for(int k = 0; k < 8; k++){
            int x = i + dx[k], y = j + dy[k];
            bool end = 0;
            while(x >= 1 && x <= 8 && y >= 1 && y <= 8 && board[x][y] >= 1){
                if(board[x][y] == id)end = 1;
                x += dx[k], y += dy[k];
            }
            x = i + dx[k], y = j + dy[k];
            if(end == 1){
                while(x >= 1 && x <= 8 && y >= 1 && y <= 8 && board[x][y] >= 1){
                    if(board[x][y] == id)break;
                    else {
                        if(id == 1){
                            count_black--;
                            count_white++;
                        }
                        if(id == 2){
                            count_black++;
                            count_white--;
                        }
                        board[x][y] = 3 - board[x][y];//reverse
                    }
                    x += dx[k], y += dy[k];
                }
            }
        }
    }
};

struct Player{
    int id;
};

struct Game{
    Board board;
    Player p1, p2;
    int turn_player;
    bool finished;
    Game(){
        p1.id = 1;
        p2.id = 2;
        turn_player = p1.id;
        finished = 0;
    }

    void PrintResult(int id, string state) {
        if(state != "Draw")cout << "Player " << id << " won!" << endl;
        else cout << "Draw." << endl;
        cout << "State is " << '"' << state << '"' << '.' << endl;
    }

    //正しいコマンドが受け取られたか判定
    bool CommandReceive(){
        string command;
        cin >> command;
        if(command == "retire"){
            PrintResult(3 - turn_player , "retired");
            finished = 1;
            return 1;
        }else if(command.size() == 2 && command[0] >= '1' && command[0] <= '8' && command[1] >= '1' && command[1] <= '8'){
            int i = command[0] - '0', j = command[1] - '0';
            if(board.board[i][j] != 0)return 0;
            bool valid = board.is_placable(turn_player, i, j);
            if(valid)board.place(turn_player, i, j);
            return valid;
        }else{
            return 0;
        }
    }
    
    void Play(){
        int unplacable_seq = 0;
        while(1){
            if(finished == 1)break;
            board.PrintBoard();
            if(board.count_black + board.count_white == 64 || unplacable_seq == 2){
                int won_id;
                if(board.count_black > board.count_white)won_id = 1;
                if(board.count_black < board.count_white)won_id = 2;
                if(board.count_black == board.count_white)won_id = 0;
                if(won_id >= 1){
                    PrintResult(won_id, "Normal");
                }else{
                    PrintResult(won_id, "Draw");
                }
                cout << board.count_black << " - " << board.count_white << endl;
                finished = 1;
            }
            bool placable_exist = 0;
            for(int i = 1; i <= 8; i++){
                for(int j = 1; j <= 8; j++){
                    if(board.is_placable(turn_player, i, j))placable_exist = 1;
                }
            }
            if(!placable_exist){
                unplacable_seq++;
                turn_player = 3 - turn_player;
                cout << "There is no placable cell, passed." << endl;
                continue;
            }else{
                unplacable_seq = 0;
            }
            cout << "Player " << turn_player << ", enter a command." << endl;
            bool valid = CommandReceive();
            if(valid){
                turn_player = 3 - turn_player;
            }else{
                cout << "Invalid command, redo." << endl;
                continue;
            }
        }
    }
};

int main(){
    Game g;
    g.Play();
}