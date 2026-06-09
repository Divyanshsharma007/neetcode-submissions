class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curmin =1;
        int curmax =1;

        int n = nums.size();

        for(int i =0 ;i <n ;i++){
            if(nums[i]<0){
                swap(curmax ,curmin);
            }

            curmax = max(nums[i],nums[i]*curmax);
            curmin = min(nums[i],nums[i]*curmin);

            res = max(res ,curmax);
        }
        return res;
    }
};
