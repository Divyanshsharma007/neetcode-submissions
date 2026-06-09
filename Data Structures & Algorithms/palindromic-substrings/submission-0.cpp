class Solution {
public:
    int countSubstrings(string s) {
        int ans =0 ;
        int n =s.size();
        for(int i = 0; i< n;i++){
            ans += expand(s, i, i);
            ans += expand(s, i, i + 1);
        }
        return ans;
    }
    int expand(string &s ,int left ,int right){
        int count = 0;

        while(left >= 0 && right<s.size() && s[left] ==s[right]){
            count++;
            left--;
            right++;
        }
        return count;
        
    }
};
