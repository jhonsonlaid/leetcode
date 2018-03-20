class Solution{
public:
    vector<string> letterCombinations(string digits){
        // record left and right
        int d2c[10][2];
        d2c[2][0] = 'a';
        d2c[2][1] = 'a'+2;
        for(int i = 3; i <= 9; ++i){
            d2c[i][0] = d2c[i-1][1] + 1;
            if(i == 7 || i == 9)
                d2c[i][1] = d2c[i-1][1] + 4;
            else
                d2c[i][1] = d2c[i-1][1] + 3;
        }
        vector<string> tmp, phone;
        for(int i = 0; i <digits.size(); ++i){
            int d = digits[i] - '0';
            for(int j = d2c[d][0]; j <= d2c[d][1]; j++){
				if(phone.empty())
				{
					string s(1, char(j));
					tmp.push_back(s);
				}
                for(int k = 0; k < phone.size(); k++){
                    tmp.push_back(phone[k] + char(j));
                }
            }
            phone.clear();
            phone.assign(tmp.begin(), tmp.end());
            tmp.clear();
        }
        return phone;
    }
};
