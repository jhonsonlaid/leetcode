class Solution {
public:
    string simplifyPath(string path) {
        string item, res;
        stringstream ss(path);
        vector<string> v;
        while(getline(ss, item, '/')){
            if(item == "." || item == "") continue;
            else if(item == ".."){
                if(!v.empty()) 
                    v.pop_back();
            }
            else v.push_back(item);
        }
        for(int i = 0; i < v.size(); i++){
            res += "/";
            res += v[i];
        }
        return res.empty() ? "/" : res;
    } 
};
