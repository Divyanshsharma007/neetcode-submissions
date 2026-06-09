class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>parti;
        int n = s.size();
        if(n == 0){
            result.push_back(parti);
        }      
        f(s ,parti ,result);
        return result;
        
    }

    void f(string s , vector<string>&parti ,vector<vector<string>>&result)
    { 
        if(s.empty()) {
          result.push_back(parti);
          return;
}
        int n = s.length();
        for(int i=0 ;i<n ;i++){
        string part = s.substr(0 ,i+1);        
        if(ispalindrome(part))
        {
            parti.push_back(part);
            f(s.substr(i + 1) , parti , result);
            parti.pop_back();
        }
        }
    }

    bool ispalindrome(string s){
        int n = s.length();
        int l =0;
        int r =n-1;
        while(l<r)
        {
        if(s[l]!=s[r])
          {
            return false;
          }
          else{
            l++;
            r--;
          }
        }
        return true;
    }
};
