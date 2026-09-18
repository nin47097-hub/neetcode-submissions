#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(
        std::vector<std::string>& strs
    ) {
        
        std::unordered_map<std::string, std::vector<std::string>> anagram_groups;

        for (const std::string& str : strs) {
            std::string key = str;

            std::sort(key.begin(), key.end());

            anagram_groups[key].push_back(str);
        }

        std::vector<std::vector<std::string>> result;

        for (auto& pair : anagram_groups) {
            result.push_back(pair.second);
        }

        return result;
    }
};


        


        

