#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // All sides are equal and all diagonals are equal
    // Hence, a Set will contain only 2 enteries
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1==p2||p1==p3||p1==p4||p2==p3||p2==p4||p3==p4){
            return false;
        }
        int s1 = abs((p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]));
        int s2 = abs((p3[0]-p2[0])*(p3[0]-p2[0])+(p3[1]-p2[1])*(p3[1]-p2[1]));
        int s3 = abs((p4[0]-p2[0])*(p4[0]-p2[0])+(p4[1]-p2[1])*(p4[1]-p2[1]));
        int s4 = abs((p1[0]-p3[0])*(p1[0]-p3[0])+(p1[1]-p3[1])*(p1[1]-p3[1]));
        int d1 = abs((p1[0]-p4[0])*(p1[0]-p4[0])+(p1[1]-p4[1])*(p1[1]-p4[1]));
        int d2 = abs((p3[0]-p4[0])*(p3[0]-p4[0])+(p3[1]-p4[1])*(p3[1]-p4[1]));
        set<int> s;
        s.insert(s1);
        s.insert(s2);
        s.insert(s3);
        s.insert(s4);
        s.insert(d1);
        s.insert(d2);
        if(s.size()==2){
            return true;
        }
        return false;
    }
};