
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root == nullptr){
            return {};

        }

        std::queue<TreeNode*>myque;

        myque.push(root);
        while(!myque.empty()){
            int s  =  myque.size();
            for(int i =0; i<s; i++){
                TreeNode* j = myque.front();
                myque.pop();
                if(i == s-1){
                    result.push_back(j->val);
                }

                if(j->left != nullptr){
                    myque.push(j->left);
                }
                if(j->right != nullptr){
                    myque.push(j->right);

                }


            }

        }
        return result;



     
        
    }
};
