class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res=INT_MIN;
        
        int n=heights.size();
        int i=0,j=n-1;
        
           while(i < j) {
        int area = abs(min(heights[i], heights[j]) * (j - i));
        res = max(res, area);

        if(heights[i] < heights[j]) i++;
        else j--;
    }
        
        return res;
    }
};
