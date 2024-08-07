#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTime(int nod,vector<int>& informTime,unordered_map<int,vector<int>>& adj){
        if(adj.find(nod)==adj.end()){
            return 0;
        }
        int time = informTime[nod];
        int maxi = 0;
        for(auto el:adj[nod]){
            int tim = findTime(el,informTime,adj);
            maxi = max(maxi,tim);
        }
        time += maxi;
        return time;

    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n==1){
            return informTime[0];
        }
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<manager.size();i++){
            if(manager[i]==-1){
                continue;
            }
            adj[manager[i]].push_back(i);
        }
        int time = informTime[headID];
        int maxi = 0;
        for(auto el:adj[headID]){
            int tim = findTime(el,informTime,adj);
            maxi = max(maxi,tim);
        }
        return time+maxi;
    }
};