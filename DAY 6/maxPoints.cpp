#include <bits/stdc++.h>
using namespace std;


// find the slope of every point with each other

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        if (points.size() <= 2) {
            return points.size();
        }

        int maxi = 1;
        
        for(int i=0;i<points.size();i++){
            map<pair<int,int>, int> m;
            // cout<<points[i][0]<<endl;
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i+1;j<points.size();j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int dx = x2-x1;
                int dy = y2-y1;

                int gcd = __gcd(dx, dy);
                dx /= gcd;
                dy /= gcd;

                if(dx==0){
                    dy = abs(dy);
                }

                cout<<x2<<" "<<y2<<" "<<"{"<<dx<<","<<dy<<"}"<<endl;
                // m[{dy,dx}].insert({x1,y1}); 
                ++m[{dy,dx}];
                maxi = max(maxi,m[{dy,dx}]);
            }
        }
        return maxi+1; 
    }   
};