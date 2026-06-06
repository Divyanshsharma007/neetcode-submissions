class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxcount =0;
        

        for(int i = 0;i<n ;i++){
            for(int j= 0; j< m ; j++){
                if(grid[i][j]==1)
                {
                    int count =0;
                    dfs(i,j,m,n,grid,count);
                    maxcount = max(count ,maxcount);
                }
            }
            
        }
        return maxcount;
        
    }
    void dfs(int r ,int c ,int m ,int n ,vector<vector<int>>& grid ,int& count){

        if(r<0 || c<0 || r>=n || c>= m || grid[r][c] == 0) return ;

        grid[r][c]= 0;
        count++;

        dfs(r+1 ,c ,m ,n, grid,count);
        dfs(r-1 ,c ,m ,n, grid,count);
        dfs(r ,c+1 ,m ,n, grid, count);
        dfs(r ,c-1 ,m ,n ,grid,count);


    }
};
