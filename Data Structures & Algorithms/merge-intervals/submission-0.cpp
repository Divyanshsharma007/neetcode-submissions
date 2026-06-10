class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> result ;

        for (auto &it : intervals) {            
            if (result.empty() || result.back()[1] < it[0]) {
                result.push_back(it);
            }
            else {                
                result.back()[1] = max(result.back()[1], it[1]);
            }
        }
        return result;  
    }
};
