class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int ob =0 ;
        int cb = 0;
        vector<string>result;
        helper(result ,0 ,0 ,n ,"");
        return result;
        
    }
    void helper(vector<string>&result ,int ob ,int cb ,int n ,string s ){
        if(ob == n && cb==n){
            result.push_back(s);
            return ;
        }
        if(ob<n){
            helper(result ,ob + 1 ,cb ,n ,s+"(");
        }
        if(cb<ob){
            helper(result ,ob ,cb+1 ,n ,s+")");
        }
    }
};
