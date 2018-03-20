class Solution{
public:
    int lengthOfLastWord(string s){
        int last_space = -1, last_char = -1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ' && i < s.length() - 1 && s[i+1] != ' ')
                last_space = i;
            if(s[i] != ' ')
                last_char = i;
        }
        return last_char == -1 ? 0 : last_char - last_space;
    }
};
