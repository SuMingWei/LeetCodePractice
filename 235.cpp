// 235. Lowest Common Ancestor of a Binary Search Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // since it's BST
        while(root != nullptr){
            if(root->val < p->val && root->val < q->val){
                root = root->right;
            }else if(root->val > p->val && root->val > q->val){
                root = root->left;
            }else{
                return root;
            }
        }
        
        return root;
    }
};