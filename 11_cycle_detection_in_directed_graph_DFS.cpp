#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node, int visited[], int dfsvisited[], vector<int> adj[]){
    visited[node] = 1;
    dfsvisited[node] = 1;
    
    for(auto it : adj[node]){
        if(!visited[it]){
            if(checkCycle(it, visited, dfsvisited, adj)) return true;
        }
        else if(dfsvisited[it]) return true;
    }
    dfsvisited[node]=0;
    return false;
}

bool cycle(int v, vector<int> adj[]){
    int visited[v];
    int dfsvisited[v];
    
    memset(visited, 0, sizeof visited);
    memset(dfsvisited, 0, sizeof dfsvisited);
    
    for(int i=0; i<v; i++){
        if(visited[i] == 0){
            if(checkCycle(i, visited, dfsvisited, adj)) return true;
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
    }
    if(cycle(n, adj)) cout<<"Yes";
    else cout<<"No";
    
    return 0;
}
