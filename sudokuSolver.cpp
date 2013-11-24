#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

bool checkValid(vector<string>& board, int x, int y){
	bool flags[9] = {0};
	for(int i = 0; i < 9; ++i)
		if(board[x][i] >= '1' && board[x][i] <= '9'){
			if(!flags[board[x][i] - '1'])
				flags[board[x][i] - '1'] = true;
			else
				return false;
		}
	memset(flags, 0, 9);
	for(int i = 0; i < 9; ++i)
		if(board[i][y] >= '1' && board[i][y] <= '9'){
			if(!flags[board[i][y] - '1'])
				flags[board[i][y] - '1'] = true;
			else
				return false;
		}
	int xx = x/3*3;
	int yy = y/3*3;
	memset(flags, 0, 9);
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			if(board[xx+i][yy+j] >= '1' && board[xx+i][yy+j] <= '9'){
				if(!flags[board[xx+i][yy+j]-'1'])
					flags[board[xx+i][yy+j]-'1'] = true;
				else
					return false;
			}
	return true;
}

bool solve(vector<string> &board){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] != '.')
                continue;
                    
            for(char k = '1'; k <= '9'; k++){
                board[i][j] = k;
                if(checkValid(board,i,j)){
					if(solve(board))
						return true;
				}
            }
            board[i][j] = '.';
            return false;
        }
    }
    return true;
}

void solveSudoku(vector<vector<char> > &board) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<string> out;
    for (int i=0; i< board.size(); i++){
        string x;
        for (int j=0; j<board[i][j]; j++) {
            x.append(1,board[i][j]);
        }
        out.push_back(x);
    }
    if (solve(out))
    {
        for (int i=0; i< out.size(); i++){
            for (int j=0; j<out[i].size(); j++) {
                board[i][j] = out[i][j];
            }
        }
        return;
    }
}

int main() {
    vector<vector<char> > board;
    string a[] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    for (int i=0; i<9; i++) {
        vector<char> temp;
        for (int j=0; j<a[i].size(); j++) {
            temp.push_back(a[i][j]);
        }
        board.push_back(temp);
        temp.clear();
    }
    solveSudoku(board);
    for (int i=0; i<9; i++) {
        for (int j=0; j<board[i].size(); j++) {
            cout<<board[i][j];
        }
        cout<<endl;
    }
}
