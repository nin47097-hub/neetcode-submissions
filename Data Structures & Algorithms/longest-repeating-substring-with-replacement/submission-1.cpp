#include<unordered_map>
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>c;
        int l =0;
        int max_len =0;
        int max_freq=0;

        for(int i =0;i<s.size();i++){
            c[s[i]]++;
            max_freq = max(max_freq,c[s[i]]);

            while(((i-l+1)-max_freq)>k){
                c[s[l]]-=1;
                l+=1;


            }

            max_len = max(max_len,(i-l+1));

        }
        return max_len;

        
        
        
    }
};
