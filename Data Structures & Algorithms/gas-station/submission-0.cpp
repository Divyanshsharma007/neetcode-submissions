class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n =gas.size();
        int m = cost.size();
        int fuel =0;
        int tgas =0;
        int tprice=0;
        int start =0;

        for(int car:gas){
            tgas = tgas+ car;
        }

        for(int price:cost){
            tprice =tprice +price;
        }

        if(tgas<tprice){
            return -1;
        }

        for(int i =0 ;i< n;i++){
            fuel = fuel + gas[i] -cost[i];
            if(fuel<0){
                fuel = 0;
                start =i+1;
            }
        }
    return start;
        
    }
};
