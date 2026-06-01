class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int n = nums.size();
        //frequency bharo
        unordered_map<int ,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        //number aur frequency ke pair banao{freq ,number}
        vector<pair<int ,int>>arr;
        for(const auto& p :freq){
            arr.push_back({p.second , p.first});
        }
        //descending mai sort kardo
        sort(arr.rbegin() , arr.rend());

        vector<int>res;
        for(int i =0 ; i<k ;i++){
            res.push_back(arr[i].second);
        }
        return res;
    }
};
