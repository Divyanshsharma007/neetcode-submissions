class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // make the adjacency list
        vector<vector<int>>adj(numCourses);
        for(auto it :prerequisites){
            int c = it[0];
            int r = it[1];
            adj[r].push_back(c);
        }

        //formulate thhe indegree list
        vector<int>indegree(numCourses ,0);
        for(int  i= 0 ; i<numCourses;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        // push the indegree 0s
        queue<int>q;
        for(int i =0 ; i<numCourses ;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        //topo/result array 
        vector<int>topo ;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it :adj[node])
            {
                indegree[it] --;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
            if(topo.size() == numCourses)return topo;
        }
        return {};
    }
};
