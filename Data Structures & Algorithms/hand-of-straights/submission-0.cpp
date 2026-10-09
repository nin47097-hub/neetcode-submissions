class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0){
            return false;
        }
        unordered_map <int, int> count;
        for(int n: hand){
            count[n]++;
        }
        sort(hand.begin(), hand.end());

        for(int i =0; i< hand.size(); i++){
            int currentcard = hand[i];
            if(count[currentcard]==0){
                continue;
            }

            for(int j =0; j< groupSize;j++){
                int nextcard = currentcard+j;

                if(count[nextcard]==0){
                    return false;
                }
                count[nextcard]--;
            }





        }

        return true;
    }
};
