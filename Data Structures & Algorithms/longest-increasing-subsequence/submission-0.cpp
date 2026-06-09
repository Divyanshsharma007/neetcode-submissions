class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // Extend LIS
            if (temp.empty() || nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            }
            else {
                // Find first element >= nums[i]
                auto it = lower_bound(
                    temp.begin(),
                    temp.end(),
                    nums[i]
                );
                // Replace with smaller tail
                *it = nums[i];
            }
        }
        return temp.size();

        
    }
};
