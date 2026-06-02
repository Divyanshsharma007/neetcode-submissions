class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(char ch: s){
            if(isalnum(ch)){
                ans = ans + (char)tolower(ch);
            }
        }
        string rev(ans.rbegin() ,ans.rend());
        if(rev == ans) return true;
        else return false;
    }
};
