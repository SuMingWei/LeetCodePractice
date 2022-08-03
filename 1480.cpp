// 1480. Running Sum of 1d Array
// https://leetcode.com/problems/running-sum-of-1d-array/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int tmp=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            tmp += nums[i];
            ans.push_back(tmp);
        }
        return ans;
    }
};
