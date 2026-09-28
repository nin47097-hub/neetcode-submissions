
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);



        
    }

private:
    int dfs(TreeNode* node, int max_vall){
        if(node == nullptr){
            return 0;
        }

        int count = 0;
        
        if(node->val >= max_vall){
            count+=1;
        }
        max_vall = max(max_vall, node->val);

        
        count+= dfs(node->left, max_vall);
        count+= dfs(node->right, max_vall);
        return count;
    }

};
