/* from left to right, if see stk is empty and there is ')',
 * then this ')' is a seperate point, store this pos in sep vec
 * from right to left, same as above, if stk is empty and see '(',
 * this '(' is redundant, push pos to sep vec
 * the result is to find the longest distance between sep point.
 */
class Solution{
public:
    int longestValidParentheses(string s){
        char l = '(', r = ')';
        stack<int> stk;
        vector<int> sep;
        int len = 0, max_len = 0;

        for(int i = 0; i < s.length(); i++){
            if(stk.empty() && s[i] == r){
                sep.push_back(i);
            }
            else if(s[i] == l){
                stk.push(i);
            }
            else if(s[i] == r){
                stk.pop();
            }
        }

        while(!stk.empty()) stk.pop();
        for(int i = s.length()-1; i >=0; i--){
            if(stk.empty() && s[i] == l){
                sep.push_back(i);
            }
            else if(s[i] == r){
                stk.push(i);
            }
            else if(s[i] == l){
                stk.pop();
            }
        }

        sep.push_back(-1);
        sep.push_back(s.length());
        sort(sep.begin(), sep.end());
        for(int j = 1; j < sep.size(); j++)
        {
            int len = sep[j] - sep[j-1] -1;
            if(len > max_len)
                max_len = len;
        }
        return max_len;
    }
};
