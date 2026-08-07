class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1,count=0;
        bool flag=false,flag1=true;
        for(int i=0;i<nums.size();i++)
        {
            if (nums[i]==0)
            {flag=true;//check if 0 exists in array
            count++;
            }
            else if(nums[i]!=0)
            flag1=false;
        }
        if(flag1==true)
        {
            vector<int> res1(nums.size(),0);
            return res1;
        }
        for(int i=0;i<nums.size();i++)
        {
        if(nums[i]!=0)
        prod=prod*nums[i];//gives us product 
        }
    vector<int> res;
    for(int i=0;i<nums.size();i++)
    {
        if(count>1){
        res.push_back(0);
        }
        else
        {
        if(nums[i]!=0 && flag==true)
        res.push_back(0);
        else if(nums[i]==0)
        res.push_back(prod);
        else
        res.push_back(prod/nums[i]);
        }
    }
    return res;

    }
};
