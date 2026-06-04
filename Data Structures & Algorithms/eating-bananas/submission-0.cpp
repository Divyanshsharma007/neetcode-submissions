class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        int l =1 ;
        int r = *max_element(piles.begin(),piles.end());

        while(l<r)
        {
            int mid = l + (r-l)/2;
            int hours =0;
            for(int banana:piles)
            {
                hours += ceil((double)banana / mid);
                if (hours>h) break;
            }
            if(hours <=h)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};
