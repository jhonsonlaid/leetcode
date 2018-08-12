class Solution{
public:
    int mySqrt(int x){
        long lo = 0, hi = x, mid;
        while(hi >= lo){
            mid = lo + ((hi - lo) >> 1);
            if(mid * mid <= x && (mid + 1) * (mid + 1) > x){
                break;
            }
            else if(mid * mid > x){
                hi = mid -1;
            }
            else if(mid * mid < x){
                lo = mid + 1;
            }
        }
        return mid;
    }
};
