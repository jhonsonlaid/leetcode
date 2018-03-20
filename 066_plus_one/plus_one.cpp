class Solution{
public:
    vector<int> plusOne(vector<int>& digits){
        int ds = digits.size();
        int extra = 1;
        for(int i = ds-1; i>=0; i--){
            if(digits[i] + extra >= 10){
                digits[i] = digits[i] + extra - 10;
                extra = 1;
            }
            else{
                digits[i] = digits[i] + extra;
                extra = 0;
            }
        }
        if(extra != 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
