class Solution{
public:
    bool isValid(string s){
        stack<char> stk;
        unordered_map<char, char> ci = {
            {']', '['},
            {'}', '{'},
            {')', '('}
        };
        for(int i = 0; i < s.length(); i++){
            //if stack empty or '(', '{', '['
			if(ci.find(s[i]) == ci.end())
				stk.push(s[i]);
            else if(stk.empty())
                return false;
			else if(ci[s[i]] != stk.top())
				return false;
			else
				stk.pop();
        }
        return stk.empty();
    }
};
