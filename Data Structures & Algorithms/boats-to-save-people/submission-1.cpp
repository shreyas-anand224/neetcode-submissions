class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0,j=people.size()-1;
        int count=0;
        sort(people.begin(),people.end());
        set<int> s;
        while(i<j)
        {
            if(people[i]+people[j]>limit)
            {
                count++;
                s.insert(j);
                j--;
            }
            else
            {
                count++;
                s.insert(i);
                s.insert(j);
                i++;
                j--;
            }
        }//now i==j
        if(!s.count(i))
        count++;
      
        return count;
    }
};