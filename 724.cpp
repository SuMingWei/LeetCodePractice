// 724. Find Pivot Index
// https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre;
        vector<int> post;
        int preSum = 0;
        int postSum = 0;
        for(int i=0;i<nums.size();i++){
            preSum += nums[i];
            postSum += nums[nums.size()-1-i];
            pre.push_back(preSum);
            post.push_back(postSum);
        }
        reverse(post.begin(),post.end());
        for(int i=0;i<nums.size();i++){
            if(pre[i] == post[i]) return i;
        }
        return -1;
        
    }
};