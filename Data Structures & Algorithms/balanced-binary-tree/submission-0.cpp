
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)!= -1;
    }

private:
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int left_val = dfs(root->left);
        if(left_val ==-1){
            return -1;
        }
        int right_val = dfs(root->right);
        if(right_val==-1){
            return -1;
        }

        if(abs(left_val- right_val)>1){
            return -1;
        }
        return max(left_val, right_val) + 1;
    }
        
    
};
