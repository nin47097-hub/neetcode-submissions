#include <vector>
#include <unordered_set>
#include <string> 

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        std::vector<int> count(26, 0);


        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        

        for (int k = 0; k < count.size(); k++) {
            if (count[k] != 0) {
                return false;
            }
        }
        return true;
    }
};

