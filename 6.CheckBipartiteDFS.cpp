#include<bits/stdc++.h>
using namespace std;

bool bipartitedfs(int node, int color[], vector<int> adj[]){
    //if not colored then color the node, this will run just for the first node of any component
    if(color[node] == -1) color[node] = 1;
    
    //traverse for all adjacent nodes
    for(auto it : adj[node]){
        //if not colored then color it and call recursion
        if(color[it] == -1){
            color[it] = 1-color[node];
            //if at any point recursion returns false then return false, no need to check further
            if(!bipartitedfs(it, color, adj)) return false;
        }
        //if node is already colored with the same color as parent then return false
        else if(color[it] == color[node]) return false;
    }
    
    //if all condition passes then return true
    return true;
}

bool bipartite(int v, vector<int> adj[]){
    int color[v];
    memset(color, -1, sizeof color);
    for(int i=0; i<v; i++){
        if(color[i] == -1){
            if(!bipartitedfs(i, color, adj)) return false;
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