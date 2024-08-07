#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adj, vector<bool>& visited, int u){
        if(visited[u]){
            return;
        }
        visited[u] = true;
        for(auto &v:adj[u]){
            if(!visited[v]){
                dfs(adj,visited,v);
            }
        }

    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){                
                ans++;
                dfs(adj,visited,i);
            }
        }
        return ans-1;
    }
};