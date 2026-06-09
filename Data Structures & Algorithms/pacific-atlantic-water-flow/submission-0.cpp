class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n  = heights.size();
        int m = heights[0].size();

        vector<vector<int>>pacific(n ,vector<int>(m,0));
        vector<vector<int>>atlantic(n ,vector<int>(m,0));

        queue<pair<int,int>> pacificq;
        queue<pair<int,int>> atlanticq;;

        for(int i =0 ;i <n ;i++){
            pacific[i][0]=1;
            pacificq.push({i,0});
            atlantic[i][m-1] =1;
            atlanticq.push({i,m-1});
        }

        for(int j= 0;j <m ;j++){
            pacific[0][j] =1;
            pacificq.push({0 ,j});
            atlantic[n-1][j]=1;
            atlanticq.push({n-1,j});
        }

        bfs(pacificq ,pacific , heights);
        bfs(atlanticq , atlantic , heights);

        vector<vector<int>>result ;
        for(int i =0 ;i < n ;i++){
            for(int j =0 ;j< m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }

    return result;

    }
    void bfs(queue<pair<int ,int>>&q ,vector<vector<int>> & visited,vector<vector<int>>&heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        while(!q.empty())
        {
            pair<int ,int>curr =q.front();
            q.pop();

            int r =curr.first;
            int c =curr.second;

            int dr[4] = {1 ,-1 , 0 , 0};
            int dc[4] = {0 , 0 ,-1 , 1};

            for(int i =0 ;i < 4;i ++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr< 0 || nc<0 || nr>=n || nc>=m) continue;
                if(visited[nr][nc]) continue;

                if(heights[nr][nc]>=heights[r][c])
                {
                    visited[nr][nc] =1;
                    q.push({nr ,nc});
                }
            }
        }      
    }
};
