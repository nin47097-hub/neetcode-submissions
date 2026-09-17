class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }

        vector<int>s1_size(26,0);
        vector<int>s2_size(26,0);

        for(int i = 0; i< s1.size();i++){
            s1_size[s1[i]-'a']++;
            s2_size[s2[i]-'a']++;
        }


        if(s1_size==s2_size){
            return true;
        }

        else{
            for(int i=s1.size();i<s2.size();i++){
                s2_size[s2[i] - 'a']++;
                s2_size[s2[i - s1.size()] - 'a']--; 


                if(s1_size==s2_size){
                    return true;
                }
                

                

            }
            return false;

        }
        
    }
};
