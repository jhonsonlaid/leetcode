class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> res(n, vector<int>(n, 0));
        int e = 1;
        for(int i = 0; i < n / 2; i++){
            //top
            for(int j = i; j < n - i - 1; j++)
                res[i][j] = e++;
            //right
            for(int j = i; j < n - i - 1; j++)
                res[j][n-1-i] = e++;
            //bottom
            for(int j = n - i - 1; j > i; j--)
                res[n-1-i][j] = e++;
            //left
            for(int j = n - i - 1; j > i; j--)
                res[j][i] = e++;
        }
        if(n % 2)
            res[n/2][n/2] = e;
        return res;
    }
};
