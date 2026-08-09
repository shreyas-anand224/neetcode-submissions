class Solution {
public:

    int target;

    bool  solve(int i, int k , int currsum, vector<int> & nums,vector<bool> & used){

        int n=nums.size();

        if(k==0)
            return true;
        
        if(currsum==target)
            return solve(0,k-1,0,nums,used);
        
        //else add to the current subset here

        for(int index=i;index<n;index++)
        {
            if(used[index])
                continue;

             if(currsum + nums[index] > target)
                continue;

            used[index]=true;
            
            currsum+=nums[index];

            if(solve(index+1,k,currsum,nums,used))//for the present subset either choose this element and mark it chosen gloablly then solve the problem or dont choose this element as given by the backtrack
                return true;

            used[index]=false;

            currsum-=nums[index];//backtrack

            
        }

        return false;
        


    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int total = 0;
        int n=nums.size();

        for(auto x : nums)
            total+=x;
        
        if(total%k != 0)
            return false;
        
        target=total/k;

        vector<bool> used(n,false);

        return solve(0,k,0,nums,used);//ie still have k-1 subsets here to assign to



    }
};