#include<iostream>
#include<vector>
using namespace std;

bool isValid(int row, int col, vector<int> &tempMoves){
    // Check for LEFT ROW
    for (int i = 0; i < col; i++){
        if(tempMoves[i] == row) return false;
    }
    
    // Check for UPPER LEFT DIAGONAL
    for(int i = 0; i < col; i++){
        if(tempMoves[col - i - 1] == row - i - 1) return false;
    }

    // Check for LOWER LEFT DIAGONAL
    for(int i = 0; i < col; i++){
        if(tempMoves[col - i - 1] == row + i + 1) return false;
    }

    return true;
}

void findWays(string* board, vector<int> &tempMoves, int col, int &cnt){
    if(col == 8){
        cnt++;
        return;
    }

    for(int row = 0; row < 8; row++){
        if(board[row][col] == '.' && isValid(row, col, tempMoves)){
            tempMoves.push_back(row);
            findWays(board, tempMoves, col + 1, cnt);
            tempMoves.pop_back();
        }
    }
}

int main(){
    string board[8];
    for(int i = 0; i < 8; i++){
        cin >> board[i];
    }
    vector<int> tempMoves;
    int cnt = 0;
    findWays(board, tempMoves, 0, cnt);
    cout << cnt << endl;
}
