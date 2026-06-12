class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto flight : flights)
        {
            int f1 = flight[0];
            int f2 = flight[1];
            int cost = flight[2];

            adj[f1].push_back({f2 ,cost});
        }

       queue<vector<int>>q;
       q.push({ 0 ,src ,0});
       vector<int>dist(n ,1e9);
       dist[src]=0;

       while(!q.empty()){
           auto it = q.front();
           q.pop();
           int stops =it[0];
           int dest = it[1];
           int cost = it[2];

           if(stops> k) continue;

           for( auto iter : adj[dest]){
                int nnode = iter.first;
                int nweight =iter.second;

                if(cost + nweight < dist[nnode] ){
                    dist[nnode] = cost + nweight;
                    q.push({stops +1 ,nnode , cost +nweight});
                }
           }
       }
       if(dist[dst] ==1e9)return -1;
       else return dist[dst];

    }
};
