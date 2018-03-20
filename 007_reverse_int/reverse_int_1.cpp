class Solution{
public:
    int reverse(int x){
        long int res = 0;
		while(x != 0){
            res = res * 10 + x % 10;
            x = x / 10;
        }
        res = res > INT_MAX || res < INT_MIN ? 0 : res;
        return res;
    }
};
