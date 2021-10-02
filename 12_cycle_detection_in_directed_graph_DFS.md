# Detect cycle in directed graph

Here we can't use the old method which we had used in undirected graph, as in undirected graph we had kept the track of visited array which would tell us that if you visit the node again then it has cycle, but here we can see that in this example

![Screenshot from 2021-08-29 20-46-11](https://user-images.githubusercontent.com/42698268/131255981-301d9f49-9317-4559-9ca8-2c5888c01e61.png)


![Screenshot from 2021-08-29 20-46-21](https://user-images.githubusercontent.com/42698268/131255983-8cb279a3-d36e-4b89-ae65-c0b38804a5b6.png)

If we'll have a visited array then for the nodes 3, 4, 5, 6, it will tell us that it is a cycle because when we'll go to 3 then 4 then 5 and mark all 3 as visited, now when we'll go to 6 it will tell us that there is an adjacent node to 6 whic is already visited and that is 5, but it doesn't know that it is stil not making a cycle so along with visited array, we'll keep track of directed visited i.e, we'll take a dfsVis which will tell us that whetehr the particular node is visited for this direction or not.

![Screenshot from 2021-08-29 21-01-06](https://user-images.githubusercontent.com/42698268/131256106-2db59f55-3e9a-41c0-b388-0f6af419196e.png)

what we will do is, we'll have two visited arrays called ```vis``` and a ```dfsVis```, whenever we will visit a node we will mark it as visited in vis as well as dfsVis, but when the dfs function will return i.e we are returning from that node because there is no further nodes to visit so we'll mark the dfsVis to be 0 again because now we are returning from that direction.

# Time complexity and space complexity
* Time complexity would be ```O(N+E)``` due to simple DFS call
* Space complexity would be ``` O(N+E) + O(N) + O(N) + O(N)``` adjacency list, visited array, dfs visited and auxilliary space for dfs call

## 0 Based Indexing

```cpp
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
```

## 1 Based Indexing

```cpp
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
    int visited[v+1];
    int dfsvisited[v+1];
    
    memset(visited, 0, sizeof visited);
    memset(dfsvisited, 0, sizeof dfsvisited);
    
    for(int i=1; i<=v; i++){
        if(visited[i] == 0){
            if(checkCycle(i, visited, dfsvisited, adj)) return true;
        }
    }
    return false;
}

int main(){
    int n, m;
    cin>>n>>m;
    
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        
        adj[u].push_back(v);
    }
    if(cycle(n, adj)) cout<<"Yes";
    else cout<<"No";
    
    return 0;
}
```
