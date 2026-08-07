class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int,int> m;
        vector<pair<int,int>> count;

        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto &x:m)
        {
            count.push_back(x);
        }
        sort(count.begin(),count.end(),[](const pair<int,int>& a,
                                const pair<int,int>& b) {
        return a.second > b.second;
    });
        for(int i=0;i<k;i++)
        {
            res.push_back(count[i].first);
        }
        return res;
    }
};
