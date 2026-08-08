class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n=arr.size();
        priority_queue<int, vector<int> ,greater<int>> pq;

        for(int i=0; i < k;i++)
        {
            pq.push(i);
        }

        for(int i=k;i<n;i++)
        {
            int top=arr[pq.top()];
            int topval=abs(x-top);
            int currval=abs(arr[i]-x);
 

            if(currval < topval)
            {
                pq.pop();
                pq.push(i);
            }

            else if((currval == topval) && (arr[i] < top) )
            {
                pq.pop();
                pq.push(i);
            }
            else
            continue;         
        }
        vector<int> res;
        while(!pq.empty())
        {
            int top=pq.top();
            pq.pop();
            res.push_back(arr[top]);
        }

        sort(res.begin(),res.end());
        return res;
    }
};