class Solution{
public:
    string addBinary(string a, string b){
        int m = a.length(), n = b.length();
        string res(m, 0);
        if(m < n)
            return addBinary(b, a);
        int carry = 0, sum = 0;
        for(int i = m-1, j=n-1; i >= 0; i--, j--){
            if(j >= 0)
                sum = a[i] + b[j] - 2 * '0';
            else
                sum = a[i] - '0';
            sum = sum + carry;
            carry = sum / 2;
            res[i] = sum % 2 + '0';
        }
        if(carry == 1)
            res.insert(res.begin(), '1');
        return res;
    }
};
