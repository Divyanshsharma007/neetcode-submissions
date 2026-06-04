class Solution {
public:
    int jump(vector<int>& nums) {
        int n =nums.size();
        int jumps =0;
        int curbest= 0;
        int maxjump =0;

        for(int i =0;i<n-1;i++){
            maxjump =max(maxjump ,i + nums[i]);

            if(i == curbest){
                jumps++;
                curbest = maxjump;
            }
        }
    return jumps;        
    }
};
