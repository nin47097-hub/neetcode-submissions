
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == nullptr){
            return root;

        }
        if(root== p || root == q){
            return root;
        }

        TreeNode* left_val = lowestCommonAncestor(root->left,p,q);
        TreeNode* right_val = lowestCommonAncestor(root->right,p,q);

        if(left_val && right_val){
            return  root;

        }
        if(left_val)  {
            return left_val;
        }
        if(right_val){
            return right_val;
        }
        return 
            nullptr;
        
    }
};
