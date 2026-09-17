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
    static bool compare(const pair<int, int> &a, const pair<int, int> &b) {
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int, int>> v;
        for(auto &i: intervals){
            v.push_back({i.start, 1});
            v.push_back({i.end, -1});
        }
        sort(v.begin(), v.end(), compare);
        int ans = 0;
        for(auto &i: v) {
            ans += i.second;
            if(ans > 1){
                return false;
            }
        }
        return true;
    }
};
