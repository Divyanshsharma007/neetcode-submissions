class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(height.empty())return 0;
        int water = 0;

        int l=0;
        int r=n-1;

        int leftmax =height[l];
        int rightmax = height[r];

        while(l<r){
            if(leftmax<rightmax){
                l++;
                leftmax = max(leftmax ,height[l]);
                water  = water + leftmax -height[l];
                
            }

            else{
                r--;
                rightmax = max(rightmax ,height[r]);
                water = water + rightmax -height[r];
            }
        }
    
    return water ;
    }
};
