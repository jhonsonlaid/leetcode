class Solution{
public:
    string convert(string s, int rows){
        string res;
        int k;
        for(int i = 0; i < rows; i++){
            for(int j = 0, k = 0; j < s.legnth(); )
            {
                res[k++] = s[i+j];
                if(i == 0 || i == rows) j += 2*(rows-1);
                else if(i < rows/2){
                    if(k % 2)  
                        j += 2*(i-1);
                    else
                        j += 2*(rows-i);
                }
                else
                {
                    if(k % 2)  
                    else
                        j += 2*(i-1);
                }
            }
        }
        return res;
    }
};
