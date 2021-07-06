#include<bits/stdc++.h>
using namespace std;

bool checkCycleBFS(int src, vector<int> &vis, vector<int> adj[]){
    queue<pair<int, int>> q;
    vis[src] = 1;
    q.push({src, -1});
    
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push({it, node});
            }
            else if(it != par) return true;
        }
    }
    return false;
}

bool isCycle(int v, vector<int> adj[]){
    vector<int> vis(v, 0);
    
    
    for(int i=0; i<v; i++){
        if(!vis[i]){
            if(checkCycleBFS(i, vis, adj)) return true;
        }
    }
    return false;
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
    if(isCycle(n, adj)) cout<<"Yes";
    else cout<<"No";
    return 0;
}
