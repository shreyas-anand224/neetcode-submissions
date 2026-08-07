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
    int minMeetingRooms(vector<Interval>& intervals) {
         map<int, int> line;
        for(auto& i : intervals){
            line[i.start]++;
            line[i.end]--;
        }
        int ans = 0;
        int count=0;
        for(auto& p : line){
            count += p.second;
            ans = max(ans, count);
        }
        return ans;
    }
};
