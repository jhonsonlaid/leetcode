/*** Longest Substring Without REpeating Characters ***/
/*** jhonsonlaid@gmail.com ***/

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int max_len=0, start=-1;
        vector<int> pre_pos(256, -1);
        for(int i=0; i<s.length(); ++i){
            int ch = s[i];
            // if(): means ch has appeared after start once, 
            // so the coming ch has duplicated
            // the new start is ch's first appearing place
            if(pre_pos[ch] > start)
                start = pre_pos[ch];
            pre_pos[ch] = i;
            max_len = max(max_len, i-start);
        }
        return max_len;
    }
};
