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
private:
    int countTree(TreeNode* root)  
    {  
         if(root == NULL) 
             return 0;
         int cl = 0, cr = 0;
        
         if(root->left) cl = countTree(root->left);
         if(root->right) cr = countTree(root->right);
        
         return cl+cr+1;
    }
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int  count = countTree(root->left) + 1;
       if(count == k) 
           return root->val;
        
       else if(count > k)
           return kthSmallest(root->left, k);
        
       else
           return kthSmallest(root->right, k-count);
    }
};
