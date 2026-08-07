class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
        {
            v[i].first=nums[i];
            v[i].second=i;
        }
        sort(v.begin(),v.end());
        int l=0,r=n-1;
        while(l<r)
        {
            int sum=v[l].first + v[r].first;
            if(sum==target){
                vector<int> result;
                if(v[l].second<v[r].second){
                result.push_back(v[l].second);
                result.push_back(v[r].second);
                }
                else
                {
                    result.push_back(v[r].second);
                result.push_back(v[l].second);
                }
                return result;
            }
            else if(sum<target)
            l++;
            else 
            r--;
        }
    }
};
