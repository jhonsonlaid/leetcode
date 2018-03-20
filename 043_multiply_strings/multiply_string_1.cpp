class Solution{
public:
    string multiply(string num1, string num2){
        string res(num1.length() + num2.length(), '0');
        for(int i = num1.length() - 1; i >= 0; i--){
            int carry = 0;
            for(int j = num2.length() - 1; j >= 0; j--){
                int sum = res[i + j + 1] - '0' + (num1[i] - '0') * 
                    (num2[j] - '0') + carry;
                res[i + j + 1] = sum % 10 + '0';
                carry = sum / 10;
            }
            res[i] = carry + '0';
        }
        int s = 0;
        for(; res[s] == '0' && s < res.length() - 1; s++);
        return res.substr(s);
    }
};
