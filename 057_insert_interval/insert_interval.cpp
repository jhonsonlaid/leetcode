/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution{
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){
        vector<Interval> res;
        int ns = newInterval.start, ne = newInterval.end; 
        int i, j, k;
        for(i = 0; i < intervals.size() && intervals[i].end < ns; i++){
            res.push_back(intervals[i]);
        }
        //cout << "i " << i << endl;
        for(j = i; j < intervals.size() && intervals[j].start <= ne; j++){
        }
        // not overlapping
        //cout << "j " << j << endl;
        if(j != i)
            res.push_back(Interval(min(ns, intervals[i].start), max(ne, intervals[j-1].end)));
        else
            res.push_back(Interval(ns, ne));

        for(k = j; k < intervals.size(); k++)
            res.push_back(intervals[k]);

        return res;
    }
};
