/* O(n) time, O(1) space
 */
class Solution{
public:
    int longestValidParentheses(string s){
        // left parenthesis counter, right parenthesis counter
        int lc = 0, rc = 0, max_len = 0;
        // from left to right, can only handle ')' as separetor 
        // ()((), not work
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                lc++;
            else if(s[i] == ')')
                rc++;

            if(lc == rc)
                max_len = max(max_len, 2 * lc);
            else if(rc > lc){
                lc = 0;
                rc = 0;
            }
        }

        lc = 0, rc = 0;
        // from right to left, can only handle '(' as separetor 
        for(int j = s.length()-1; j >= 0; j--){
            if(s[j] == '(')
                lc++;
            if(s[j] == ')')
                rc++;

            if(lc == rc)
                max_len = max(max_len , 2 * lc);
            else if(lc > rc){
                lc = 0;
                rc = 0;
            }
        }
        return max_len;
    }
};
