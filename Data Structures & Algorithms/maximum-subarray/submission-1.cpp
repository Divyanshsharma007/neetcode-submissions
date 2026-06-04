class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int total =0;
        int maxsum =nums[0];

        for(int num : nums){
            total = total + num;
            maxsum = max(maxsum ,total);
            if(total<0){
                total = 0;
            }
            
        }
    return maxsum;
    }
};
