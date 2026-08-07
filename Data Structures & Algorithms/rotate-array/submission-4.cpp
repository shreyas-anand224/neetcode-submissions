class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n=nums.size();
       if (n==1)
       return ;
       int index;
       vector<int> v;
       if(k>=n)
       k=k%n;
        index=n-k;
       if (k==0)
        return ;
       int count=0;
       while(count<n)
       {
       
        v.push_back(nums[index]);
         
        index++;
        if(index==n && count!=n-1)
        {
            index=0;
        }
        count++;
       } 
       for(int i=0;i<n;i++)
       {
        nums[i]=v[i];
       }
    }
};