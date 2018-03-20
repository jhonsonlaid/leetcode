/*** Find Longest Palindrome ***/
/*** There are two case: xyYyx and xyyx ***/
/*** O(n^2) time and O(n^2) space ***/

class Solution{
public:
    string longestPalindrome(string s){
        deque<char> deq1, deq2, deqr;
        string res;
        for(int i=0; i<s.length(); ++i){
            int j = i;
            //(i-1) - (j-i), (..., i-2, i-1, i, i+1...)
            while(2*i-j-1 >= 0 && j < s.length() && s[j] == s[2*i-j-1]){
                deq1.push_front(s[j]);
                deq1.push_back(s[2*i-j-1]);
                j++;
            } 

            j = i;
            //i - (j+1-i), i->center, (i-1, i, i+1)
            while(2*i-j-1 >= 0 && j<s.length()-1 && s[j+1] == s[2*i-j-1])
            {
               if(j == i) deq2.push_front(s[j]);
               deq2.push_front(s[j+1]);
               deq2.push_back(s[2*i-j-1]);
               j++;
            }

            if(deq1.size() > deqr.size() && deq1.size() > deq2.size()){
                deqr.clear();
                deqr.assign(deq1.begin(), deq1.end());
            }
            else if(deq2.size() > deqr.size()){
                deqr.clear();
                deqr.assign(deq2.begin(), deq2.end());
            }

            deq1.clear();
            deq2.clear();
        }

        for(int k=0; k<deqr.size(); k++)
            res.push_back(deqr[k]);

        return res.size() ? res : res=s[0];
    }
};
