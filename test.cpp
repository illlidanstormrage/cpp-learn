#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        float first_x = coordinates[0][0];
        float first_y = coordinates[0][1];
        float last_x = coordinates[n-1][0];
        float last_y = coordinates[n-1][1];
        float slope_x = last_x - first_x;
        float slope_y = last_y - first_y;
        float slope;
        if(slope_x == 0){
            slope = -100000;
        }
        else{
            slope = slope_y/slope_x;
        }
        float delta_x;
        float delta_y;
        float delta_slope;
        for(int i=1; i<n; i++){
            delta_x = coordinates[i][0] - first_x;
            delta_y = coordinates[i][1] - first_y;
            if(delta_x == 0){
                delta_slope = -100000;
            }
            else{
                delta_slope = delta_y/delta_x;
            }
            cout << delta_x << " " << delta_y << " " << delta_slope << endl;
            if(delta_slope != slope){
                return false;
            }
        }
        return true;
    }
};

int main(){
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    v1.push_back(1);
    v1.push_back(-8);
    v2.push_back(2);
    v2.push_back(-3);
    v3.push_back(1);
    v3.push_back(2);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    Solution s;
    cout << s.checkStraightLine(v) << endl;

}