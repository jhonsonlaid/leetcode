/** same as original method
 * but using long long to simplify code
 */
class Solution{
public:
    // denominator, numerator
    int divide(int dividend, int divisor){
        if(!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;

        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long den = labs(dividend);
        long dor = labs(divisor);
        int ans = 0;
        while(den >= dor){
            long in_dvs = dor, in_ans = 1;
            while(den >= (in_dvs << 1)){
                in_dvs <<= 1;
                in_ans <<= 1;
            }
            den -= in_dvs;
            ans += in_ans;
        }
        return sign == -1 ? -ans : ans;
    }
};
