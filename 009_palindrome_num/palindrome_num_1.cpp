class Solution{
public:
    bool isPalindrome(int x){
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        // right half_reverse 121-> 12, 1221-> 12
        int rhr = 0;
        while(x > rhr){
            rhr = rhr * 10 + x % 10;
            x /= 10;
        }
        return rhr == x || rhr / 10 == x;
    }
};
