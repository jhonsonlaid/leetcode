/* Time Limit Exceed*/
class Solution{
private:
    int helper(int m, int n, int& res, int dir){
        if(m == 1 || n == 1) return ++res; 
        if(dir == 1 || dir == 0){
            for(int i = 1; i < m; i++)
                helper(m-i, n, res, -1);
        }
        if(dir == -1 || dir == 0){
            for(int j = 1; j < n; j++){
                helper(m, n-j, res, 1);
            }
        }       
        return res;
    }
public:
    int uniquePaths(int m, int n){
        int res = 0;
        // dir 1: right, -1: down, 0 both
        int dir = 0;
        helper(m, n, res, 0);
        return res;
    }
};
