class Solution {
private: 
   
    vector<vector<string>> res;


    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false; 
            }
            l++;
            r--;
        }
        return true; 
    }

   
    void dfs(int start, string &s, vector<string>& part) {
        
        if (start == s.size()) {
            res.push_back(part); 
            return;
        }

        for (int end = start; end < s.size(); end++) {
   
            if (isPalindrome(s, start, end)) {
                
               
                part.push_back(s.substr(start, end - start + 1));
                
                
                dfs(end + 1, s, part);
                
               
                part.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        res.clear();         
        vector<string> part; 
        
        dfs(0, s, part);  
        
        return res;       
    }
};

