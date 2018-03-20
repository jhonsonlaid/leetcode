/*** Find Longest Palindrome ***/
/*** We noly need find the correct index ***/
/*** There are two case: xyYyx and xyyx ***/
/*** This Method can solve two cases as one ***/
/*** bab, abba, bbb, bb ***/

class Solution{
public:
    string longestPalindrome(string s){
        if(s.empty()) return "";
        if(s.length() == 1) return s;
        int start = 0, max_len = 1;
        for(int i = 0; i < s.length(); ){
			if(s.length() - i <= max_len/2) break;
            int l = i, r = i;
            // find all char==s[i] first
            // set left = i, right = same_char_last_pos
            // then aba-->a[b]a, abba-->a[bb]a is the same problem,
            // no need to solve xyAyx and xyyx respecitvely
            // set i = same_char_last_pos+1;
            while(r < s.length()-1 && s[r] == s[r+1]) r++;
            i = r + 1;
            while(r < s.length()-1 && l > 0 && s[r+1] == s[l-1]){
                r++;
                l--;
            }
            if(r-l+1 > max_len) {
                start = l;
                max_len = r-l+1;
            }
        }
        return s.substr(start, max_len);
     }
};

