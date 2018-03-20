class Solution{
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B){
        int m = A.size(), n = B.size();        
        // to ensure j exists: i.e. n should be larger
        if(m > n){
            return findMedianSortedArrays(B, A);
        }
       
        int li = 0, ri = m;

        while(true){
            int i = (li + ri) / 2;
            int j = (m + n + 1) / 2 - i;
            int la, lb, ra, rb;

            la = (i == 0) ? INT_MIN : A[i-1];
            lb = (j == 0) ? INT_MIN : B[j-1];
            ra = (i == m) ? INT_MAX : A[i];
            rb = (j == n )? INT_MAX : B[j];

            if (la > rb) ri = i - 1;
            else if (ra < lb) li = i + 1;
            else if((m + n) % 2) 
                return max(la, lb);
            else
                return (max(la, lb) + min(ra, rb)) / 2.0;
        }
    }
};
