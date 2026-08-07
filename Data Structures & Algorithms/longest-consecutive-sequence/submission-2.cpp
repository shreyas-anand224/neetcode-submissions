class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int> s;
        vector<int> v;
        for(auto &x: nums)
        {
            s.insert(x);
        }
        for(auto &x: s)
        {
            v.push_back(x);
        }
        int len;
        if(v.size()==0)
        {
                return 0;
        } 
        len=1;
        int maxi=1;
        for(int i=1;i<v.size();i++)
        {
            if(v[i]-v[i-1]==1)
            {
                len++;
                maxi=max(len,maxi);
            }
            else
            len=1;
        }
        return maxi;

    }
};
