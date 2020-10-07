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

/*
    Recursive Approach
*/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        
        if(val > root->val)
            root->right = insertIntoBST(root->right, val);
        else if(val < root->val)
            root->left = insertIntoBST(root->left, val);
        
        return root;
    }
};

/*
    Iterative Approach
*/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);

        TreeNode* current = root;
        
        while(true) {
            if(val > current->val) {
                if(current->right != NULL)
                    current = current->right;
                else {
                    current->right = new TreeNode(val);
                    break;
                }
            } else {
                if(current->left != NULL)
                    current = current->left;
                else {
                    current->left = new TreeNode(val);
                    break;
                }
            }
        }
        
        return root;
    }
};