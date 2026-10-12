class Solution {
public:
    vector<int> partitionLabels(string s) {
     
        unordered_map<char, int> last_index;
        vector<int> res;
        int start = 0;
        int end = 0;

      
        for(int i = 0; i < s.size(); i++){
            last_index[s[i]] = i; 
        }

        for(int i = 0; i < s.size(); i++){
      
            end = max(end, last_index[s[i]]);
            
            if(i == end){
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};

