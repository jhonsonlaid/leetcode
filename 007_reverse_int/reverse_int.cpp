class Solution{
public:
    int reverse(int x){
        double res = 0;
		bool is_neg = false;
		if(x < 0){
			is_neg = true;	
			x = -x;
		}
        while(x > 0){
            res = res * 10 + x % 10;
            x = x / 10;
        }
        res = res > INT_MAX ? 0 : res;
        res = is_neg ? -res : res;
        return res;
    }
};
