class Solution{
public:
    int cal_row_len(vector<string>& row){
        int row_len = 0;
        for(int i = 0; i < row.size(); i++){
            row_len += row[i].length();
        }
        return row_len;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth){
        vector<string> res;
        for(int i = 0; i < words.size(); ){
            vector<string> row;
            string str;
            int j;
            for(j = i; j < words.size(); j++){
                int row_len = cal_row_len(row);
                if(row.size() +  row_len + words[j].size() <= maxWidth){
                    row.push_back(words[j]);
                }
                else{
                    int quotient , remainder;
                    if(row.size() == 1){
                        quotient = maxWidth - row_len;
                        remainder = 0;
                    }
                    else{
                        quotient = (maxWidth - row_len) / (row.size() -1);
                        remainder = (maxWidth - row_len) % (row.size() - 1);
                    }
                    for(int k = 0; k < row.size(); k++){
                        str += row[k];
                        if(remainder > 0){
                            str += " ";
                            remainder--;
                        }
                        if(k < row.size()-1 || row.size() == 1)
                            for(int h = 0; h < quotient; h++)
                                str += " ";
                    }
                    break;
                }
            }
            if(j == words.size()){
                for(int k = 0; k < row.size(); k++){
                    str += row[k];
                    if(k != row.size() -1)
                        str += " ";
                }
                int space_num = maxWidth - str.size();
                for(int k = 0; k < space_num; k++){
                    str += " ";
                }
            }
            res.push_back(str);
            i = j;
        }
        return res;
    }
};
