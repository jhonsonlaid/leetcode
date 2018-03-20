class Solution{
public:
    bool isPalindrome(int x){
        long rx = 0;
        while(x != 0){
            rx = rx * 10 + x % 10;
            x = x / 10;
        }
        return rx == x;
    }
};
