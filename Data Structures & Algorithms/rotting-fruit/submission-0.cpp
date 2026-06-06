
class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;

        queue<pair<pair<int ,int> ,int>> q;

        for(int i = 0 ; i<n ;i++)
        {
            for(int j= 0 ;j < m;j++)
            {
                if(grid[i][j]==1)
                {
                    fresh++;
                }
                else if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }

        if(fresh == 0)return 0;

        int dr[4] = { 1, -1 ,0 , 0};
        int dc[4] = { 0 , 0 , -1 ,1};
        int minutes = 0;
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int r = it.first.first;
            int c = it.first.second ;
            int t = it.second ;

            
            minutes =max(t,minutes);

            for(int k = 0; k< 4 ;k ++)
            {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr<0 || nc<0 || nr>=n || nc>= m) continue ;
                if(grid[nr][nc]!=1) continue ;

                grid[nr][nc]=2;
                fresh--;

                q.push({{nr ,nc},t +1});

            }
        }
        
        if(fresh==0)return minutes;
        return -1;
    }
};
