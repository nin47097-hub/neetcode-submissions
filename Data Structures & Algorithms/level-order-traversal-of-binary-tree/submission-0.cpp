
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;

        if(root == nullptr){
            return result;
        }

        std::queue<TreeNode*> myQueue;

        myQueue.push(root);
        while(!myQueue.empty()){
            vector<int>k;
            
            int s =myQueue.size();
            for (int i =0;i<s;i++){
                TreeNode* l = myQueue.front();
                myQueue.pop();
                if(l !=nullptr){
                    k.push_back(l->val);
                    myQueue.push(l->left);
                    myQueue.push(l->right);

                }
                
                
            }
            if(!k.empty()){
                    result.push_back(k);

            }

        }
        
        return result;
        
    }
};
