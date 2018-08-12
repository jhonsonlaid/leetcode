class Solution{
public:
    void setZeroes(vector<vector<int>>& matrix){
        int c0 = 1, r0 =1, rows = matrix.size(), cols = matrix[0].size();
        //use first column and first row as store space
        for(int i = 0; i < rows; i++)
            if(matrix[i][0] == 0) c0 = 0;
        for(int j = 0; j < cols; j++)
            if(matrix[0][j] == 0) r0 = 0;

        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }

        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if(c0 == 0)
            for(int i = 0; i < rows; i++)
                matrix[i][0] = 0;
        if(r0 == 0)
            for(int j = 0; j < cols; j++)
                matrix[0][j] = 0;
    }

};
