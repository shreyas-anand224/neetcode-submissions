class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int res=0, curr=0;
       unordered_map<int,int> prefix;
       prefix[0]=1;/////by default prefixsum of no element here
       for(int x:nums)
       {
        curr+=x;
        int diff=curr-k;
        res+=prefix[diff];//checking if the target value is present in the prefixsum hashmap already
        prefix[curr]++;///update the count of a prefix with a given sum
       }
       return res;



    }
};