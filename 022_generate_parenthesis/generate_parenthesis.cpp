class Solution{
public:
    vector<string> generateParenthesis(int n){
        vector<string> res;
        addPar(res, "", n, 0);
        return res;
    }
    void addPar(vector<string>& vs, string substr, int l, int r){
        if(l > 0)
            addPar(vs, substr+"(", l-1, r+1);
        if(r > 0)
            addPar(vs, substr+")", l, r-1);
        if(l == 0 && r == 0){
            vs.push_back(substr);
            return;
        }
    }
};
