/*** I misunderstand the problem ***/
/*** '*' can only represent the former char(0+) ***/
/*** i.e. a*: a, aa, aaa, not a, ab, ae, a... ***/

class Solution{
public:
    bool isMatch(string s, string p){
        string subs, req;
        int i = 0, j = 0, k, l, t;
        int start = 1;
        while(j < p.length()){
            // req -> sententce end with *
            req.clear();
            while(j < p.length() && p[j] != '*'){
                start = 0;
                req.push_back(p[j++]);
            }

            // if p[j]=='*', do nothing
            if(i < s.length() && req.length()){
                //int subs.find(req); 
                int req_pos = -1;
                subs = s.substr(i);
                if(i == 0){
                    string cmp(s.substr(0, req.length()));
                    for(t = 0; t < req.length(); t++){
                        if(req[t] != cmp[t] && req[t] != '.') break;
                    }
                    if(t < req.length()) req_pos = -1;
                    else req_pos = t;
                }
                else{
                    // check if s contain req
                    for(k = 0; k < subs.length(); ){
                        if(req.length() > (subs.length() - k)) req_pos = -1;
                        l = 0;
                        while((l < req.length() && req[l] == subs[k] || req[l] == '.')){
                            l++;
                            k++;
                        }
                        if(l < req.length()){
                            req_pos = -1;
                        } 
                        else{
                            req_pos = k;
                            break;
                        }
                       if(l == 0) k++;
                    }
                }
                
                if(req_pos != -1){
                    // ..xEND
                    //if subs not contain req, i donot change
                    if(req_pos >= s.length()) return true;
                    else i = i + req_pos;
                }
            }
            
            // ..x*END
            if(p[j] == '*' && j == p.length()-1){
                return true;
            }
                       
           if(p[j] == '*') j++;
        }
        return i < s.length() ? false : true;
    }
};
