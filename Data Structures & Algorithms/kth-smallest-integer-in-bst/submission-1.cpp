class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);   
        return result;  
    }

private:
    int result = -1;
    
    
    void dfs(TreeNode* node, int& k){
        if(!node){
            return;
        }

        dfs(node->left, k);
        
        k--;
        if(k == 0){
            result = node->val;
            return; 
        }
        
        dfs(node->right, k);
    }
};
