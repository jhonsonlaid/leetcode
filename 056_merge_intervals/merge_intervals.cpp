/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool intervalCmp(Interval a, Interval b){
    return (a.start < b.start);
}

class Solution{
public:
    vector<Interval> merge(vector<Interval>& intervals){
        sort(intervals.begin(), intervals.end(), intervalCmp);
        vector<Interval> res;
        for(int i = 0; i < intervals.size(); ){
            int start = intervals[i].start;
            int end = intervals[i].end;
            int idx = i;
            while(intervals[i+1].start <= end && i+1 < intervals.size()){
                end = max(intervals[i+1].end, end);
                i++;
            }
            i++;
            res.push_back(Interval(start, end));
        }
        return res;
    }
};
