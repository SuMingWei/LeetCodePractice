// 54. Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int curOrder = 0;
        int loops = 0;
        int cnt = 0;
        int x=0,y=0;
        // first
        ans.push_back(matrix[x][y]);
        cnt++;
        // others
        while(cnt < m*n){
            if(curOrder == 0){ // right
                while(y < n-loops-1){
                    y += 1;
                    ans.push_back(matrix[x][y]);  
                    cnt++;
                }
                curOrder++;
            }else if(curOrder == 1){ //down
                while(x < m-loops-1){
                    x += 1;
                    ans.push_back(matrix[x][y]);        
                    cnt++;
                }
                curOrder++;
            }else if(curOrder == 2){ // left
                while(y > loops){
                    y -= 1;
                    ans.push_back(matrix[x][y]);        
                    cnt++;
                }
                curOrder++;
            }else if(curOrder == 3){ //up
                loops++;
                while(x > loops){
                    x -= 1;
                    ans.push_back(matrix[x][y]);        
                    cnt++;
                }
                curOrder = 0;
            }
        }
        return ans;
    }
};