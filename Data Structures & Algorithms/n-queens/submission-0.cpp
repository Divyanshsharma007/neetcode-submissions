class Solution {
public:
    vector<string>board;
    vector<bool>col;
    vector<bool>lrd;
    vector<bool>rld;
    vector<vector<string>>result;
    vector<vector<string>> solveNQueens(int n) {
        col = vector<bool>(n ,false);
        lrd = vector<bool>(2*n ,false);
        rld = vector<bool>(2*n ,false);
        board =vector<string>(n ,string( n, '.'));

        backtrack(0,n);
        return result;
        
    }
    void backtrack(int r ,int n){
        if(r== n) {
            result.push_back(board);
            return ;
        }

        for(int c =0 ; c< n ;c++){
            if(col[c]||lrd[r+c]||rld[r+n-c-1])continue;

            board[r][c] = 'Q';
            col[c]=true;
            lrd[r + c] = true;
            rld[r + n -c -1] = true;

            backtrack(r+1,n);

            board[r][c] = '.';
            col[c]=false;
            lrd[r + c] = false ;
            rld[r + n - c-1] = false;
        }
    }
};
