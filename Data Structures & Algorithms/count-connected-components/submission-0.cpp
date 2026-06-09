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
    int countComponents(int n, vector<vector<int>>& edges) {
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
};
