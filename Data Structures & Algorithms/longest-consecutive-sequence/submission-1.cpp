class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() ,nums.end());
        if(n==0)return 0;

        int  longest =1 ;
        int currl =1 ;

        for(int i= 1 ;i<n ;i++){
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]== nums[i-1]+1){
                currl++ ;                
            }
            else{
                currl =1 ;
            }

            longest = max(longest ,currl);
        }
        return longest;        
    }
};
