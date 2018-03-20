class Solution{
private:
    bool isDigit(char ch){
        return (ch - '0') >= 0 && (ch - '0') <= 9;
    }
public:
    bool isNumber(string s){
        // delete space
        while(s[0] == ' ')
            s.erase(0, 1);
        while(s[s.size() -1] == ' '){
            s.erase(s.size() -1, 1);
        }

        if(s.empty()) return false;
        // delete '+'
        if((s[0] == '+' || s[0] == '-') && s.size() > 1)
            s.erase(0, 1);

        // '.1e2'
        if(s[0] == '.'){
            s.erase(s.begin());
            // ".e1", "."
            if(s.empty() || s[0] == 'e') return false;
            while(isDigit(s[0]))
                s.erase(0, 1);
            if(s[0] == 'e' && s.size()>1){
                s.erase(0, 1);
                if((s[0] == '+' || s[0] == '-') && s.size() > 1 )
                    s.erase(0, 1);
            }
            while(isDigit(s[0]))
                s.erase(0, 1);
            return s.empty();
        }
        // 'e32'
        if(s[0] == 'e' ) return false;
        
        // "12..."
        while(isDigit(s[0]))
            s.erase(0, 1);
        
        if(s[0] == '.'){
            s.erase(0, 1);
            // "12.e"
            while(isDigit(s[0]))
                s.erase(0, 1);
        }
        if(s[0] == 'e' && s.size() > 1){
            s.erase(0, 1);
            if((s[0] == '+' || s[0] == '-') && s.size() > 1 )
                s.erase(0, 1);
        }

        while(isDigit(s[0]))
            s.erase(0, 1);
        
        return s.empty();

    }
};
