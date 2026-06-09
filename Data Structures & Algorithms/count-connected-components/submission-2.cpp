class DSU{
public:    
    vector<int>size;
    vector<int>parent;
    DSU(int n)
{
    size.resize(n,1);
    parent.resize(n);

    for(int  i =0 ;i<n ;i++){
        parent[i]=i;
    }
}

int fp(int node){
    if(parent[node] == node) return node;
    return parent[node]=fp(parent[node]);
}

void ubs(int u ,int v)
{
    int pu =fp(u);
    int pv =fp(v);

    if(pu==pv)return ;

    if(size[pu]<size[pv]){
        parent[pu] = pv;
        size[pv] = size[pv] + size[pu];
    }

    else{
        parent[pv] = pu;
        size[pu] = size[pv] + size[pu];
       }
   }
};
class Solution {
public:
    int countComponent(int n, vector<vector<int>>& edges) {
        //int m = edges.size();
        //if(m<n-1) return -1;

        DSU dsu(n);

        for(auto &c :edges){
            dsu.ubs(c[0] ,c[1]);
        }

        int connections = 0;

        for(int i =0 ;i< n;i++){
            if(dsu.fp(i)== i){
                connections ++;
            }
        }

    return connections ;

    }
    int countComponents(int n ,vector<vector<int>>& edges){
        vector<vector<int>>adj(n);
        vector<bool>visit(n ,false);

        for(auto edge : edges){
            int c1 =edge[0];
            int c2 =edge[1];
            adj[c1].push_back(c2);
            adj[c2].push_back(c1);            
        }

        int components =0 ;

        for(int i=0 ;i< n ;i++){
            if(!visit[i]){
                dfs(adj ,visit ,i);
                components++;
            }
        }
        return components;
    }
    private:
    void dfs(vector<vector<int>>& adj , vector<bool>&visit , int node){
        visit[node]= true;
        for(int nei :adj[node]){
            if(!visit[nei]){
                dfs(adj ,visit ,nei);
            }
        }
    }

};
