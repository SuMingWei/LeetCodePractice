// 173. Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/

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
class BSTIterator {
public:
    vector<int> vec;
    void inOrder(TreeNode* root){
        if(root == NULL) return;
        inOrder(root->left);
        vec.push_back(root->val);
        inOrder(root->right);
    }
    BSTIterator(TreeNode* root) {
        inOrder(root);
    }
    
    int next() {
        int x = vec[0];
        vec.erase(vec.begin());
        return x;
    }
    
    bool hasNext() {
        return !vec.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */