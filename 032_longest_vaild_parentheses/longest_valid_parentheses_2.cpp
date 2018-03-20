/* Using dynamic programming method
 * reference:<https://discuss.leetcode.com/topic/2426/my-dp-o-n-solution-without-using-stack>
 */
class Solution{
public:
    int longestValidParentheses(string s){
        if(s.length() <= 1) return 0;
        // dp stores the longest vaild str end at i 
        vector<int> dp(s.length(), 0);
        int max_len = 0;
        for(int i = 1; i < s.length(); i++){
            // i-dp[i-1]-1 is i's paired '(' index
            if(s[i] == ')' && i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '('){
               dp[i] = 2 + dp[i-1] + (i-dp[i-1]-2 >= 0 ? dp[i-dp[i-1]-2] : 0);
               max_len = max(max_len, dp[i]);
            }
        }
        return max_len;
    }
};
