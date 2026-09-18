#include<vector>
#include<stack>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>result(n,0);
        stack<int>my_stack;

        for(int i = temperatures.size()-1;i>=0;i--){
            while(!my_stack.empty() &&temperatures[my_stack.top()]<=temperatures[i]){
                my_stack.pop();
            }
            if(!my_stack.empty()){
                result[i]=my_stack.top()-i;
            }


            my_stack.push(i);

            
        }
        return result;
        
    }
};
