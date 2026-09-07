class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> freq;

        for(int num : nums){
            freq[num]++;
        }

        vector<int>res ;

        for(auto& pair : freq)
        {
            if(pair.second > n/3) res.push_back(pair.first);
        }
        return res;
    }
};