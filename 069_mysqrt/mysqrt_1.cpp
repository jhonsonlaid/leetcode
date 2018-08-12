class Solution{
public:
    int mySqrt(int x){
        if(x < 2) return x;
        int lo = 1, hi = x, mid;
        while(hi >= lo){
            mid = lo + ((hi - lo) >> 1);
            if( mid <= x / mid){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return lo-1 ;
    }
};
