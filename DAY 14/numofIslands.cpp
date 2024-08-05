// Approach:
/*
    1. Traverse Each Cell of the grid.
    2. if it is 0, continue
    3. if it is 1, increment ans by 1 and mark the current and adjacent cells to
       0 (using recursive function)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    void markIslands(vector<vector<char>>& grid, int i, int j, int row, int col){
        grid[i][j] = '0';

        if(i>0 && grid[i-1][j]=='1'){
            markIslands(grid,i-1,j,row,col);
        }
        if(i<row-1 && grid[i+1][j]=='1'){
            markIslands(grid,i+1,j,row,col);
        }
        if(j>0 && grid[i][j-1]=='1'){
            markIslands(grid,i,j-1,row,col);
        }
        if(j<col-1 && grid[i][j+1]=='1'){
            markIslands(grid,i,j+1,row,col);
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='0'){
                    continue;
                }
                ans++;
                markIslands(grid,i,j,row,col);
            }
        }
        return ans;
    }
};