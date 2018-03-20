class Solution{
public:
    // denominator, numerator
    int divide(int dividend, int divisor){
        if(!divisor)
            return INT_MAX;

        // as abs(INT_MIN) > INT_MAX ,so we need to take it as special case
        if(dividend == INT_MIN){
            if(divisor == 1) return INT_MIN;
            else if(divisor == -1) return INT_MAX;
            // divisor & 1 ? even : odd;
            else return (divisor&1) ? divide(dividend+1, divisor)
                : divide(dividend>>1, divisor>>1);
        }
        if(divisor == INT_MIN) return 0;

        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        int ans = 0;
        while(dividend >= divisor){
            int in_dvs = divisor, in_ans = 1;
			// in_dvs should be smaller than INT_MAX
            while(in_dvs < INT_MAX>>1 && dividend >= in_dvs<<1){
				in_dvs <<= 1;
                in_ans <<= 1;
            }
            dividend -= in_dvs;
            ans += in_ans;
        }
        return sign == -1 ? -ans : ans;
    }
};
