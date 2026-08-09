class Solution {
public:

    int len;
    vector<vector<int>> ans;

    void solve(int index, vector<int> & curr, vector<int> & nums)
    {
        int n=nums.size();

        if(curr.size()==len)
            ans.push_back(curr);
        
        for(int i=index;i<n;i++)
        {
            curr.push_back(nums[i]);

            solve(i+1,curr,nums);

            curr.pop_back();

        }
    }

    vector<vector<int>> combine(int n, int k) {

        len=k;
        vector<int> nums;
        vector<int> curr;

        for(int i=1;i<=n;i++)
            nums.push_back(i);
       
        solve(0,curr,nums);

    return ans;
        
    }
};