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
    int count(TreeNode* root){
        if (root==NULL){
            return 0;
        }
        int left=count(root->left);
        int right=count(root->right);

        if(left==-1 || right==-1 || abs(left-right)>1){
            return -1;
        }
    
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        return count(root)!=-1;
        
    }
};
