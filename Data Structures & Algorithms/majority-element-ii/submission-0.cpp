class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        int count=n/3;
        map<int,int> m;
        for( auto &x : nums)
        {
            m[x]++;
        }
        for(auto &x:m)
        {
            if (x.second > count)
            res.push_back(x.first);
        }
        return res;


    }
};