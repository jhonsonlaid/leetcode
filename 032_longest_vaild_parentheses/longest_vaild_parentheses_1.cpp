class Solution{
public:
    int longestValidParentheses(string s){
        int max_len = 0;
        char lp = '(' , rp = ')';
        stack<int> stk;
        // attention, for "|()()|()|", 
        // we should take pos -1 and pos n into account
        stk.push(-1);
        for(int i = 0; i < s.length(); i++){
            if(s[i] == lp){
                stk.push(i);
            }
            else if(s[i] == rp){
                if(!stk.empty() && s[stk.top()] == lp) stk.pop();
                else stk.push(i);
            }
        }
        // last is pos n
        int first, last = s.length();
        while(!stk.empty()){
            first = stk.top();
            stk.pop();
            max_len = max(max_len, last-first-1);
            last = first;
        }
        return max_len;
    }
};
