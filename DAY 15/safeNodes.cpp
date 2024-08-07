#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafeNode(vector<vector<int>>& graph,unordered_map<int,bool>& safeNodes, int node, vector<bool>& visited, vector<int>& ans){
        if(visited[node]){
            return safeNodes[node];
        }
        visited[node] = true;

        if(graph[node].empty()){
            ans.push_back(node);
            return safeNodes[node] = true;
        }

        for(auto neighbour:graph[node]){
            if(!isSafeNode(graph,safeNodes,neighbour,visited,ans)){
                return false;
            }
        }
        ans.push_back(node);
        return safeNodes[node] = true;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        vector<bool> visited(graph.size(),false);
        unordered_map<int,bool> safeNodes;

        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                isSafeNode(graph,safeNodes,i,visited,ans);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }   
};