class Solution {
public:
    
    int diameterOfBinaryTree(TreeNode* root) {
        int max_val =0;
        dfs(root,max_val);
        return max_val;
    }
private:
    int dfs(TreeNode*root, int&max_val){
        if(!root){
            return 0;
        }
        int left = dfs(root->left, max_val);
        int right = dfs(root->right, max_val);
        max_val = max(max_val ,left+right);
        return 1+max(left, right);
    }
};
