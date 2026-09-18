#include<vector>
#include<algorithm>
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> my_pair;
        for(int i =0;i<position.size();i++){
            my_pair.push_back({position[i], speed[i]});

        }
        sort(my_pair.rbegin(), my_pair.rend());
        vector<double>my_stack;

        for (auto& p : my_pair){
            my_stack.push_back((double)(target-p.first)/p.second);
            if(my_stack.size()>=2 && my_stack.back() <= my_stack[my_stack.size()-2]){
                my_stack.pop_back();
            }
        }
        return my_stack.size();






        
    }
};
