#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std; // Added to make string and vector visible

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return ""; 
        }

        vector<int> s_size(128, 0);
        vector<int> t_size(128, 0);
        int formed = 0;
        int min_length = INT_MAX;
        int l = 0;
        int start_idx = -1;
        int r = 0; 

        for (char c : t) {
            t_size[c]++;
        }
        
        for (int i = 0; i < 128; i++) {
            if (t_size[i] > 0) {
                r++;
            }
        }

        for (int k = 0; k < s.size(); k++) {
            s_size[s[k]]++;

           
            if (t_size[s[k]] > 0 && t_size[s[k]] == s_size[s[k]]) {
                formed++;
            }

            while (formed == r) {
                if (k - l + 1 < min_length) {
                    min_length = k - l + 1;
                    start_idx = l;
                }

          
                s_size[s[l]]--; 

                if (t_size[s[l]] > 0 && s_size[s[l]] < t_size[s[l]]) {
                    formed--;
                }

                l++;
            }
        }
        return start_idx == -1 ? "" : s.substr(start_idx, min_length);
    }
};
