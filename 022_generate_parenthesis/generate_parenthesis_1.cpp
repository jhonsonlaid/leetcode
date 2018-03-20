/*** iterative method -- dynamic program 
 * f(n) = "("+f(0)+")"+f(n-1) + ... + "("+f(i)+")"+f(n-1-i) + ... + "("+f(n-1)+")"+f(0)
 * reference: <https://discuss.leetcode.com/topic/3474/an-iterative-method>
 */

class Solution{
public:
    vector<string> generateParenthesis(int n){
        //if using [] operator, the program should assign space first.
        // so "res(n+1)"
        vector<vector<string> > res(n+1);
        res[0].push_back("");
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                for(int l = 0; l < res[j].size(); l++){
                    for(int r = 0; r < res[i-1-j].size(); r++){
                        res[i].push_back("(" + res[j][l] + ")" + res[i-1-j][r]);
                    }
                }
            }
        }
        return res[n];
    }
};
