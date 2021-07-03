#include<bits/stdc++.h>
using namespace std;

vector<int> topoSortBFS(int v, vector<int> adj[]){
    queue<int> q;
    vector<int> inDegree(v, 0);
    vector<int> topo;
    
    //store the in degree of all nodes
    for(int i=0; i<v; i++){
        for(auto it : adj[i]){
            inDegree[it]++;
        }
    }
    
    //push all having indegree 0 in queue
    for(int i=0; i<v; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    
    //kanhs algorithm or bfs
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        
        for(auto it : adj[node]){
            inDegree[it]--;
            if(inDegree[it] == 0){
                q.push(it);
            }
        }
    }
    
    return topo;
}

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
    }
    
    vector<int> ans = topoSortBFS(n, adj);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
