class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int gass = 0;
        int station =0;

        if (accumulate(gas.begin(), gas.end(), 0) <
            accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        for(int i =0; i< gas.size(); i++){
           
            gass+=  gas[i]- cost[i];
            if(gass<0){
                gass=0;
                
                station=i+1;
                

            }

        }
        return station;


        
        
    }
};
