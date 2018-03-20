class Solution{
public:
	double myPow(double x, int n){
		if (x == 0) return 0;
		if (n == 0) return 1;
		if (n == -INT_MIN){
			n++;
			x *= x;
		}
		if (n < 0){
			n = -n;
			x = 1 / x;
		}
		return n & 1 ? x * myPow(x * x, n / 2) :
			myPow(x * x, n / 2);
	}
};
