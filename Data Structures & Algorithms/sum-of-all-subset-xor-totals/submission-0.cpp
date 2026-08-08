class Solution {
public:
    int sum=0;

    void solve(int i, int currsum, vector<int> & nums)
    {
        int n=nums.size();
        if(i==n)
        {
            sum+=currsum;
            return;
        }

        solve(i+1,currsum^nums[i],nums);

        solve(i+1,currsum,nums);

    }

    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();

        int currsum=0;
        solve(0,currsum,nums);

        return sum;

        
    }
};