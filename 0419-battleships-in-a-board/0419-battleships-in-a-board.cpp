class Solution {
public:
    bool check(int i, int j, int &n, int &m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void func(vector<vector<char>>& board, int i, int j, int &n, int &m){
        board[i][j] = '.'; //change the board on the go
        if(check(i, j+1, n, m) && board[i][j+1] == 'X'){//going right
            func(board, i, j+1, n, m);
        }else if(check(i+1, j, n, m) && board[i+1][j] == 'X'){//going down
            func(board, i+1, j, n, m);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'X'){
                    count++;
                    func(board, i, j, n, m);
                }
            }
        }
        return count;
    }
};