class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n==0)return ;
        int m = board[0].size();
        

        for(int i =0 ; i< m ;i++){
           if(board[0][i]=='O'){
            dfs( 0, i , n , m , board);
           }
           if(board[n-1][i]=='O'){
            dfs(n-1 ,i , n , m ,board);
           }
        }

        for(int j =0 ; j< n ;j++){
           if(board[j][0]=='O'){
            dfs( j, 0 , n , m , board);
           }
           if(board[j][m-1]=='O'){
            dfs(j ,m-1 , n , m ,board);
           }
        }

        for(int i = 0; i< n; i++)
        {
          for(int  j= 0 ; j< m ;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }

            }
        }

         for(int i = 0; i< n; i++)
        {
          for(int  j= 0 ; j< m ;j++)
            {
                if(board[i][j]=='#')
                {
                    board[i][j]='O';
                }

            }
        }
        
    }
    void dfs(int r , int c , int n , int m ,vector<vector<char>>&board){

        if(r<0 || c< 0 || r>= n || c>=m || board[r][c] != 'O') return ;

        board[r][c] ='#';

        dfs(r+1 ,c, n , m ,board) ;
        dfs(r-1 ,c, n , m ,board) ;
        dfs(r ,c+1, n , m ,board) ;
        dfs(r ,c-1, n , m ,board) ;       
        
    }
};
