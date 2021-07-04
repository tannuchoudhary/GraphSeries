#include<bits/stdc++.h>
using namespace std;

// the basic idea is to check if the graph can generate topological sort array, then it does not contain cycle 
// because we know that graph can generate topo sort only if it is DAG
// so just write the code of topo sort and find out if the length of generated topo sort is equal to number of vertices then it does not contain cycle

bool cycleBFS(int v, vector<int> adj[]){
    queue<int> q;
    vector<int> inDegree(v, 0);
    
    //find the indegree of all the nodes
    for(int i=0; i<v; i++){
        for(auto it : adj[i]){
            inDegree[it]++;
        }
    }
    
    //insert all having indegree 0 in the queue
    for(int i=0; i<v; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }
    
    //count will keep record of number of elements in topo sort
    int count =0;
    
    //kanhs algorithm 
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        for(auto it : adj[node]){
            inDegree[it]--;
            if(inDegree[it] == 0)
                count++;
        }
    }
    
    //if elements in topo sort equals to total vertices then graph is DAG therefore, no cycle
    if(count == v) return false;
    
    else return true;
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
    
    if(cycleBFS(n, adj)) cout<<"Yes";
    else cout<<"No";
    
    return 0;
}
