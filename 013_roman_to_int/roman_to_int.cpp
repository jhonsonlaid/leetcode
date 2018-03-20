class Solution{
public:
    int romanToInt(string s){
        int i = 0, ans = 0;
        if(!s.length()) return 0;
        while(i < s.length() && 'M' == s[i]){
            ans += 1000;
            i++;
        }
        if(i+1 < s.length() && 'C' == s[i] && 'M' == s[i+1]){
            ans += 900;
            i += 2;
        }
        if(i+1 < s.length() && 'C' == s[i] && 'D' == s[i+1]){
            ans += 400;
            i += 2;
        }
        if(i < s.length() && 'D' == s[i]){
            ans += 500;
            i++;
        }
        while(i < s.length() && 'C' == s[i]){
            ans += 100;
            i++;
        }
        if(i+1 < s.length() && 'X' == s[i] && 'C' ==s[i+1]){
            ans += 90;
            i += 2;
        }
        if(i+1 < s.length() &&'X' == s[i] && 'L' == s[i+1]){
            ans += 40;
            i += 2;
        }
        if(i < s.length() && 'L' == s[i]){
            ans += 50;
            i++;
        }
        while(i < s.length() && 'X' == s[i]){
            ans += 10;
            i++;
        }
        if(i+1 < s.length() &&'I' == s[i] && 'X' == s[i+1]){
            ans += 9;
            i += 2;
        }
        if(i+1 < s.length() &&'I' == s[i] && 'V' == s[i+1]){
            ans += 4;
            i += 2;
        }
        if(i < s.length() && 'V' == s[i]){
            ans += 5;
            i++;
        }
        while(i < s.length() && 'I' == s[i]){
            ans += 1;
            i++;
        }
        return ans;
    }
};
