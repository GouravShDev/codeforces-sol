#include<bits/stdc++.h>
using namespace std;
#define sync_off ios::sync_with_stdio(0);cin.tie(0);
#define ll long long int


int main(){
    sync_off;
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
    #endif
    
    return 0;
}

  int spanningTree(int V, vector<vector<int>> adj[])
    {
        // { weight, u , v} 
        vector<vector<int>> nodes;
        
        for(int i =0 ; i < V; i++){
            for(int j = 0 ; j < adj[i].size(); j++){
                auto adjN= adj[i][j];
                nodes.push_back({adjN[1], i, adjN[0]});
            }
        }
        sort(nodes.begin(), nodes.end());
        DisjointSet ds(V);
        int ans = 0;
        for(auto node: nodes){
            int u = node[1];
            int v= node[2];
            if(ds.find(u) != ds.find(v)){
                ans += node[0];
                ds.connect(u,v);
                
            }
        }
        return ans;
    }