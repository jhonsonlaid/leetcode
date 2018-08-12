class Solution{
public:
    string fractionToDecimal(int numerator, int denominator){
        string sign;
        long num = numerator, den = denominator;
        if(num * den < 0) sign = "-";
        num = abs(num), den = abs(den);
        long quotient = num / den;
        long remainder = num % den;
        string ans = to_string(quotient) + (remainder > 0 ? "." : "");
        map<long, int> rem_map;
        while(remainder > 0){
            if(rem_map.find(remainder) != rem_map.end()){
                ans.insert(rem_map[remainder], "(");
                ans += ")";
                break;
            }
            rem_map[remainder] = ans.size();
            num = remainder * 10;
            quotient = num / den;
            remainder = num % den;
            cout << num << endl;
            ans += to_string(quotient);
        }
        return sign + ans;
    }
};
