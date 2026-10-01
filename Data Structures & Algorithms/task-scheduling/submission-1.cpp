class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::vector<int>freq(26,0);

        for(char i: tasks){
            freq[i-'A'] ++;
        }

        int max_freq = 0;
        for(int k : freq){
            max_freq = std::max(max_freq, k);
        }

        int count =0;
        for(int j =0; j<26; j++){

            if(freq[j]==max_freq){
                count++;
            }
        }

        return std::max((int)tasks.size(), (max_freq - 1) * (n + 1) + count);



        
        
    }
};
