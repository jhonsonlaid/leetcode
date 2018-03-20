class Solution{
public:
    int romanToInt(string s){
        unordered_map<char, int> ci = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int i = s.length()-2;
        int ans = ci[s.back()];
        while(i >= 0){
            if(ci[s[i]] < ci[s[i+1]])
                ans -= ci[s[i]];
            else
                ans += ci[s[i]];
            i--;
        }
        return ans;
    }
};
