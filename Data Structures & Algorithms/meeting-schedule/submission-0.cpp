/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int count=0;
        map<int,int> mp;
        for(auto x :intervals)
        {
            mp[x.start]++;
            mp[x.end]--;
        }
        for(auto x :mp)
        {
            count+=x.second;
            if (count>1)
                return false;
        }
        return true;
    }
};
