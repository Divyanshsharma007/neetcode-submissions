class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int total =0;
        int maxsum =nums[0];

        for(int num : nums){
            if(total<0){
                total = 0;
            }
            total = total + num;
            maxsum = max(maxsum ,total);
        }
    return maxsum;
    }
};
