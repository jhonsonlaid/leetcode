class Solution{
public:
    int numDecodings(string s){
        int n = s.size();
        vector<int> dp(n+1, 0);
        if(s[0] == '0') return 0;
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            if(s[i-1] != '0'){
                dp[i] = dp[i-1];
            }
            if(i >= 2 && s[i-2] != '0' && 
               stoi(s.substr(i-2, 2)) <= 26){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
