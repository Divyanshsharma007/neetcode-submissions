class DSU{
public:
    vector<int>size;
    vector<int>parent;

   DSU(int n)
   {
     parent.resize(n+1);
     size.resize(n+1,0);
     for(int i =0 ;i<= n ;i++)
     {
        parent[i]= i;
     }
   }

   int fp(int node){
     if(parent[node]== node) return node;
     return parent[node] =fp(parent[node]);
   }

   void ubs(int u ,int v)
   {
     int pv = fp(v);
     int pu = fp(u);

     if(size[pu] <size[pv]){
        parent[pu]= pv;
        size[pv] = size[pu] + size[pv];
     }
     else{
        parent[pv]= pu;
        size[pu] = size[pu] + size[pv];
     }
   }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for(auto edge :edges){
            int e1 =edge[0];
            int e2 =edge[1];
            if(dsu.fp(e1)==dsu.fp(e2)){
                return edge;
            }

            dsu.ubs(e1,e2);
        }
        return{};
    }
};
