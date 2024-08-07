//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCyclicBFS(int nod, vector<bool>& visited,vector<int> adj[] ){
        unordered_map<int,int> parent;
        parent[nod] = -1;
        queue<int> q;
        q.push(nod);
        visited[nod] = true;
        
        while(!q.empty()){
            int frnt = q.front();
            q.pop();
            
            for(auto neighbour:adj[frnt]){
                if(visited[neighbour] && neighbour!=parent[frnt]){
                    return true;
                }
                else if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                    parent[neighbour] = frnt;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans = isCyclicBFS(i,visited,adj);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends