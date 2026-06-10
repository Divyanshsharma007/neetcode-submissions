class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        vector<int>pse(n);
        vector<int>nse(n);
        PSE(pse ,heights);
        NSE(nse ,heights);
        int maxarea =0;

        for(int i = 0 ;i<n ;i++){
            int width = nse[i] -pse[i] -1 ;
            int area  = heights[i]*width;
             maxarea = max(area ,maxarea);
        }
        return maxarea;
    }

    void PSE(vector<int>&pse , vector<int>& heights)
    {
        int n =heights.size();
        stack<int>st;
    for(int i = 0 ;i<n;i++){
        while(!st.empty()&& heights[st.top()]>=heights[i])
        {
            st.pop();
        }
        if(st.empty()){
            pse[i]=-1;
        }
        else{
            pse[i]=st.top();
        }
        st.push(i);
      }
    }

    void NSE(vector<int>&nse , vector<int>& heights)
    {
        int n =heights.size();
        stack<int>st;
    for(int i = n-1 ;i>=0;i--){
        while(!st.empty()&& heights[st.top()]>=heights[i])
        {
            st.pop();
        }
        if(st.empty()){
            nse[i]=n;
        }
        else{
            nse[i]=st.top();
        }
        st.push(i);
      }
    }
};
