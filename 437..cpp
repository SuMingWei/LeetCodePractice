// 437. Path Sum III
// https://leetcode.com/problems/path-sum-iii/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<long long> &vec, int &ans){
        if(root == NULL) return;
        
        vec.push_back(root->val);
        solve(root->left, targetSum, vec, ans);
        solve(root->right, targetSum, vec, ans);
        
        int n = vec.size();
        long long val=0;
        for(int i=n-1;i>=0;i--){
            val += vec[i];
            if(val == targetSum) ans++;
        }
        
        vec.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        
        int ans=0;
        vector<long long> vec;
        solve(root, targetSum, vec, ans);
        return ans;
    }
};