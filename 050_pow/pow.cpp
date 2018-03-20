class Solution{
public:
	double myPow(double x, int n){
		double res = 1;
		// 7 = ((2 + 1)* 2 + 1)
		if (n == INT_MIN){
			n++;
			x *= x;
		}
		for (int i = abs(n); i > 0; i /= 2){
			if (i & 1) res *= x;
			x *= x;
		}
		if (res == 0) return 0;
		return n < 0 ? 1 / res : res;
	}
};
