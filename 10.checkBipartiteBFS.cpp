#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(int src, int color[], vector<int> adj[]){
    queue<int> q;
    color[src] = 1;
    q.push(src);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(color[it]==-1){
                color[it] = 1-color[node];
                q.push(it);
            }
            else if(color[it] == color[node]) return false;
        }
    }
    return true;
}

bool bipartite(int v, vector<int> adj[]){
    int color[v];
    memset(color, -1, sizeof color);
    
    for(int i=0; i<v; i++){
        if(color[i] == -1){
            if(!checkBipartite(i, color, adj)) return false;
        }
    }
    
    return true;
}

int main(){
    int n, m;
    cin>>n>>m;
    
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    
    if(bipartite(n, adj)) cout<<"Yes";
    else cout<<"No";
    
    return 0;
}
