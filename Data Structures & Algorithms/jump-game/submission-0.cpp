class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int manzil = 0;
        for(int i =0 ;i<n ; i++){
            if(i> manzil) return false ;
            manzil =max(manzil ,i + nums[i]);
        }
    return true;
    }
};
