class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m =grid[0].size();
        int count =0;

        for(int i =0 ;i<n ;i++)
        {
            for(int  j= 0;j<m ;j++)
            {
                if(grid[i][j] =='1')
                {
                  count++;
                  dfs(grid ,i ,j ,0 , m ,n );
                }
            }
        }
        return count ;
    }
    void dfs(vector<vector<char>>&grid , int r , int c ,int count , int m , int n){
        //int n = grid.size();
        //int m =grid[0].size();

        if(r<0 || c<0 || r>=n || c>=m || grid[r][c]=='0' )return;

        grid[r][c]='0' ;
        dfs(grid , r-1 ,c ,count ,m , n);
        dfs(grid , r+1 ,c ,count ,m , n);
        dfs(grid , r ,c+1 ,count ,m , n);
        dfs(grid , r ,c-1 ,count ,m , n);


        
    }
};
