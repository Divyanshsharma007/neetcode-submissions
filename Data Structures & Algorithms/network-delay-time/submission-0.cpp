class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int ,int>>>adj(n+1);
        
        for(auto time :times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v ,w});
        }

        vector<int>dist(n+1 , 1e9);
        dist[k] = 0;

        priority_queue<pair<int ,int> ,vector<pair<int,int>> ,greater<pair<int,int>>>pq;
        pq.push({0,k});

        while(!pq.empty()){
            auto [time , node] = pq.top();
            pq.pop();

            for( auto&neigh :adj[node]){
                int next = neigh.first;
                int wt = neigh.second;

                int newtime = time + wt ;

                if(newtime < dist[next]){
                    dist[next] =newtime;
                    pq.push({newtime , next});
                }
            }
        }
        int result = 0;
        for(int i =1 ;i <= n ;i ++)
        {
            if(dist[i] == 1e9)
            {
                return -1;
            }
                result = max(result,dist[i]);
            
        }

        return result;

    }
};
