class Solution {
private:

    bool dfs(TreeNode* node, long left, long right){

        if(!node){
            return true;
        }


        if(node->val <= left || node->val >= right){
            return false;
        }


        return dfs(node->left, left, node->val) && dfs(node->right, node->val, right);
    }

public:
    bool isValidBST(TreeNode* root) {
      
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};
