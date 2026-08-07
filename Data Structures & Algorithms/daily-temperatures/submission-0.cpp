class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int>res(n,0);
        // find next greeater
        for (int i = 0; i < n; i++) {
            int ele = nums[i];
            while (!st.empty() && ele > nums[st.top()]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i); 
        }
        return res;
    }
};