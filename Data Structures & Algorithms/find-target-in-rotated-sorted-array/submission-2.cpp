class Solution {
public:
    int search(vector<int>& nums, int target) {
     int low=0,high=nums.size()-1;
     while(low<high)//for seraching minima/pivot here-> since r is a possible ans here
     {
        int mid=(high+low)/2;
        if(nums[mid]>nums[high])//then pivot is on the right here
        {
            low=mid+1;
        }
        else
        high=mid;
     }
     int pivot=low;
     low=0,high=nums.size()-1;//or high since they are equal here;
    if(target>=nums[pivot]&& target<=nums[high])
    low=pivot;
    else
    high=pivot-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target)
        return mid;
        else if(nums[mid]<target)
        low=mid+1;
        else
        high=mid-1;
    }
    return -1;

    }
};
