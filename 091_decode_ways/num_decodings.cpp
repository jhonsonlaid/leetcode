/*
 * Time Limit Exceed
 */
class Solution{
public:
    void helper(string s, int k, int& cnt){
        if(k >= s.size()){
            cnt++;
            return;
        }
        if(s[k] != '0'){
            helper(s, k+1, cnt);
        }
        if(k+1 < s.size() && s[k] != '0' && 
           stoi(s.substr(k, 2)) <= 26){
            helper(s, k+2, cnt);
        }
    }
    int numDecodings(string s){
        int cnt = 0;
        helper(s, 0, cnt);
        return cnt;
    }
};
