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
    static bool compare(const pair<int, int> &a, const pair<int, int> &b){
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> times(intervals.size()*2);

        for(int i = 0; i < intervals.size(); i++) {
            times[2*i] = {intervals[i].start, 1};
            times[2*i+1] = {intervals[i].end, -1}; 
        }

        sort(times.begin(), times.end(), compare);

        int ans = 0;
        int curr = 0;

        for(auto &x: times){
            curr = curr + x.second;
            ans = max(ans, curr);
        }
        return ans;
    }
};
