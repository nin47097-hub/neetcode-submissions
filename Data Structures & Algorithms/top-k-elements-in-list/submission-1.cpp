#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
       
        vector<pair<int, int>> int_array;
        for (const auto& p : count) {
            int_array.push_back({p.second, p.first});
        }
      
        sort(int_array.rbegin(), int_array.rend());
        
   
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(int_array[i].second); 
        }
        
        return result;
    }
};

