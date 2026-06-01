class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int ,int >freq;
        for(int num :nums){
            if(freq.count(num)>=1){
                return true;
            }
            freq[num]++;
        }
        return false;
    }
};