class Solution{
public:
    vector<int> findSubstring(string s, vector<string>& words){
        vector<int> res;
        if(words.empty()) return res;
        int wl = words[0].length(), ws = words.size();
        for(int i = 0; i <= s.length(); i++){
            vector<int> found(words.size(), 0);
            if(i + wl * ws > s.length()) break;
            int pre_mch = -1, cur_mch = 0, j;
            for(j = i; j < i + wl * ws && cur_mch > pre_mch; j += wl){
                string str = s.substr(j, wl);
                pre_mch = cur_mch;
                for(int k = 0; k < ws; k++){
                    if(found[k] == 0 && words[k].compare(str) == 0){
                        found[k] = 1;
                        cur_mch++;
                        break;
                    }
                }
            }
            if(cur_mch == ws)
                res.push_back(i);
            
        }
        return res;
    }
};
