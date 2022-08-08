// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/

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
    // check whether the node is valid BST by recursive
    bool check(TreeNode* root, long long l, long long r){
        if(root == NULL) return true;
        if(root->val > l && root->val < r){
            bool checkLeft = check(root->left, l, root->val);
            bool checkRight = check(root->right, root->val, r);
            return checkLeft && checkRight;
        }   
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return check(root, -pow(2,31)-1, pow(2,31));
    }
};