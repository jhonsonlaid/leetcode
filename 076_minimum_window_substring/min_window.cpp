class Solution{
public:
    string minWindow(string s, string t){
        vector<int> dict(128, 0);
        for(int i = 0; i < t.length(); i++){
            dict[t[i]]++;
        }
        int head, start = 0, end = 0, counter = t.size(), d = INT_MAX;
        // we define window contains all characters of t as full window
        // the outter while loop search s[end] > 0, stops at counter==0, and get full window[start, end]
        while(end < s.size()){
            if(dict[s[end]] > 0) counter--;
            dict[s[end]]--;
            end++;

            // the inner loop increment start to move window forward and stops at counter == 1
            // (the [start+1, end] window is not full window then, and has new search target s[start])
            while(counter == 0){
                if((end - start) < d){
                    d = end - start;
                    head = start;
                }
                // the start of the current min_full_window contains t
                // move forward , then it's not full window, need to search s[start], so counter++
                if(dict[s[start]] == 0) counter++;
                dict[s[start]]++; // only s[start] > 0, outter loop will search s[start]
                start++; // move forward(this window need to get new s[start] to be full window)
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};
