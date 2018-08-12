class Solution{
public:
    int numDecodings(string s){
        int n = s.size();
        vector<int> dp(n, 0);
        if(s[0] == '0') return 0; 
        dp[0] = 1;
        for(int i = 0; i < n; i++);{
            bool found = false;
            if(s[i] != '0'){
                s[i] = s[i-1] + 1;
                found = true;
            }
            if(i >= 2 && i+1 < n && s[k] != '0' && 
               stoi(s.substr(k, 2)) <= 26){
                s[i] = s[i-2] + 1;
                found = true;
            }
            if(!found) return 0;
        }
        return dp[n-1];
    }
};
