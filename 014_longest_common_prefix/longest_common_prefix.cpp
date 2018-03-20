class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        int min_len = INT_MAX, min_idx = 0;
        if(!strs.size()) return "";
        for(int i = 0; i < strs.size(); i++){
            if(strs[i].length() < min_len){
                min_len = strs[i].length();
                min_idx = i;
            }
        }
        for(int j = 0; j < min_len; j++)
            for(int k = 0; k < strs.size(); k++){
                if(strs[min_idx][j]!= strs[k][j])
                    return strs[min_idx].substr(0, j);
            }
        return strs[min_idx];
    }
};
