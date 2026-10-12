class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        unordered_set<int> good;

        for(auto& k : triplets){
            if(k[0]>target[0] || k[1]>target[1]||k[2]>target[2]){
                continue;
            }

            for(int i =0; i< k.size(); i++){
                if(k[i]==target[i]){
                    good.insert(i);


                }
            }




        }
        return good.size()==3;
        
    }
};