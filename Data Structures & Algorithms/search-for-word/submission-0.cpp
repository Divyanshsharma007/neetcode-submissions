class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i =0 ; i< n ;i++)
        {
            for(int j =0 ;j<m ;j++)
            {
                if (dfs(0 , i , j, word ,board))
                {
                    return true;
                }
            }
        }

    return false;
        
    }
    bool dfs(int i ,int r ,int c, string word , vector<vector<char>> & board ){
        int n = board.size();
        int m = board[0].size();

        if(i==word.size()) return true;

        if(r<0 || c<0 || r>=n || c>=m || board[r][c]!= word[i]) return false;

        board[r][c] = '#';

        bool res = dfs(i+1 ,r+1 ,c ,word ,board) || dfs(i+1 ,r-1 ,c ,word ,board) || dfs(i+1 ,r ,c+1,word ,board) || dfs(i+1 ,r ,c-1,word,board );

       board[r][c]=word[i];
       
      return res;
    }
};
