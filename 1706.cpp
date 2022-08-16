// 1706. Where Will the Ball Fall
// https://leetcode.com/problems/where-will-the-ball-fall/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ball;
        for(int i=0;i<n;i++){
            ball.push_back(i);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ball[j] != -1){
                    // right
                    if(grid[i][ball[j]] == 1){
                        if(ball[j] == n-1) ball[j] = -1;
                        else if(grid[i][ball[j]+1] == -1) ball[j] = -1;
                        else if(grid[i][ball[j]+1] == 1) ball[j]++;
                    }// left
                    else{
                        if(ball[j] == 0) ball[j] = -1;
                        else if(grid[i][ball[j]-1] == 1) ball[j] = -1;
                        else if(grid[i][ball[j]-1] == -1) ball[j]--;   
                    }
                }
            }
        }
        return ball;
    }
};