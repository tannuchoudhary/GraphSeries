#include<bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            findTopoSort(it, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> topSort(int v, vector<int> adj[]){
    stack<int> st;
    vector<int> vis(v, 0);
    
    for(int i=0; i<v; i++){
        if(!vis[i]){
            findTopoSort(i, vis, st, adj);
        }
    }
    vector<int> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    
    return topo;
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
    
    vector<int> ans = topSort(n, adj);
    
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
        
    return 0;
}
