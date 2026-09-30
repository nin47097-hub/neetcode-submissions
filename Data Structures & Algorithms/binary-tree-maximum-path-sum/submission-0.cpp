
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_val = INT_MIN; 
        dfs(root, max_val);

        return max_val;
    }

private: 
    int dfs(TreeNode* node, int& max_val){
        if(node == nullptr){
            return 0; 
        }

       
        int left_side = max(0, dfs(node->left, max_val));
        int right_side = max(0, dfs(node->right, max_val));

       
        int currentsum = node->val + left_side + right_side;
        max_val = max(max_val, currentsum);

        return node->val + max(left_side, right_side);
    }
};

