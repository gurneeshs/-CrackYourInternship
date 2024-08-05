// Approach: Same idea as numofIslands

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>>& image, int sr, int sc, int row, int col, int color, int imgColor){
        if(image[sr][sc]==color){
            return;
        } 

        image[sr][sc] = color;
        if(sr>0 && image[sr-1][sc]==imgColor){
            solve(image,sr-1,sc,row,col,color,imgColor);
        }
        if(sc>0 && image[sr][sc-1]==imgColor){
            solve(image,sr,sc-1,row,col,color,imgColor);
        }
        if(sr<row-1 && image[sr+1][sc]==imgColor){
            solve(image,sr+1,sc,row,col,color,imgColor);
        }
        if(sr<col-1 && image[sr][sc+1]==imgColor){
            solve(image,sr,sc+1,row,col,color,imgColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }   
        int i = image.size();
        int j = image[0].size();
        int imgColor = image[sr][sc];
        solve(image, sr, sc, i, j, color, imgColor);
        return image;
    }
};