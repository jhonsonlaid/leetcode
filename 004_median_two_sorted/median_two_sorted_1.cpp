/* binary search
 */
class Solution{
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B){
        int m = A.size(), n = B.size();        
        // to ensure j exists: i.e. n should be larger
        if(m > n){
            A.swap(B);
            int tmp = m;
            m = n;
            n = tmp;
        }
        
        int li = 0, ri = m;

        while(true){
            int i = (li + ri) / 2;
            int j = (m + n + 1) / 2 - i;
            //left part shoulb be smaller than right part
            if(i > 0 && j < n && A[i-1] > B[j]){
                ri = i - 1;
            }
            else if(j > 0 && i < m && A[i] < B[j-1]){
                li = i + 1;
            }
            else{
                int left_max, right_min;
                if(i == 0) left_max = B[j-1];
                else if(j == 0) left_max = A[i-1];
                else left_max = max(A[i-1], B[j-1]);

                if(( m + n) % 2) return left_max;
                
                if(i == m) right_min = B[j];
                else if(j == n) right_min = A[i];
                else right_min = min(A[i], B[j]);

                return  (left_max + right_min)/2.0;
            }
        }
    }
};
