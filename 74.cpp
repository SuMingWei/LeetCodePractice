// 74. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row;
        for(int i=0;i<m-1;i++){
            if(target >= matrix[i][0] && target < matrix[i+1][0]){
                row = i;
                break;
            } 
        }
        
        for(int i=0;i<n;i++){
            if(matrix[row][i] == target) return true;
        }
        return false;
        
    }
};