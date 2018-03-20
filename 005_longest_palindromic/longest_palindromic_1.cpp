/*** Find Longest Palindrome ***/
/*** We noly need find the correct index ***/
/*** There are two case: xyYyx and xyyx ***/
/*** O(n^2) time and O(n) space ***/

class Solution{
public:
    string longestPalindrome(string s){
        int i, m1 = 0, m2 = 0, l1 = 0, l2 = 0;
        int max_len = 0, m = 0, l;
        string res;
        
        if(s.length() == 1) return s;
        
        for(i=0; i<s.length(); ++i){
            l1 = l2 = 0;
            while(i-l1 >= 0 && i+l1+1 < s.length() && s[i-l1] == s[i+l1+1]){
                m1 = i;
                l1++;
            } 
            while(i-l2 >= 0 && i+l2 < s.length() && s[i-l2] == s[i+l2]){
                m2 = i;
                l2++;
            }
            if(m1 == i && 2*l1 > max_len){
                m = m1;
                max_len = 2*l1;
            }
            else if(m2 == i && 2*(l2-1) >= max_len){
                m = m2;
                max_len = 2*l2-1;
            }
        }

        max_len>0 ?  (max_len%2 ? res.assign(s, m-max_len/2, max_len) :
						res.assign(s, m-max_len/2+1, max_len)) : res=s[0]; 
        return res;
    }
};
