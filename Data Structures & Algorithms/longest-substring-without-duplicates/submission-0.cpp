#include<vector>
class Solution {
public:
    int lengthOfLongestSubstring(string s){
        std::unordered_set<char>elements;
        vector<int>count_vector;
       
        int left = 0; 
        for (int right = 0; right < s.size(); right++) { 
            while (elements.find(s[right]) != elements.end()) {
                elements.erase(s[left]);
                left++;
            }
            
       
            elements.insert(s[right]);
            
           
            count_vector.push_back(right - left + 1);
        }
        
       
        if (count_vector.empty()) {
            return 0;
        }
        
     
        auto max_it = max_element(count_vector.begin(), count_vector.end());
        return *max_it;
    
    }
};
