class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m-1, r = -1, mid;
        while(lo <= hi){
            mid = (lo + hi) >> 1;
            cout << mid << endl;
            if(target >= matrix[mid][0] && target <= matrix[mid][n-1]){
                r = mid;
                break;
            } 
            else if(target > matrix[mid][0])
                lo = mid + 1;
            else if((target < matrix[mid][0]))
                hi = mid - 1;
        }

        if(r == -1) return false;
        
        lo = 0, hi = n;
        while(lo <= hi){
            mid = (lo + hi) >> 1;
            if(target > matrix[r][mid])
                lo = mid + 1;
            else if(target < matrix[r][mid])
                hi = mid - 1;
            else
                return true;
        }
        return false;
    }
};
