/***
 * Can be proved by contradiction: if not answer pair, (ai, aj)
 * say answer is : li < ai, rj > aj, then it must has been calculated
 * ai, aj, li, rj ---> index, not height
 * since we move cursor from outside to inside
 * if calculating result is (li, rj) > (ai, aj) it must has been stored in 'max_area'
 */

class Solution{
public:
    int maxArea(vector<int>& height){
        int i = 0 , j = height.size() - 1, max_area = 0;
        while(i < j){
            max_area = max(max_area, min(height[i], height[j])*(j-i));
            // always move the index of lower height
            // it ensure the inside volume must be bigger or smaller
            if(height[i] < height[j])
                i++;
            else 
                j--;
        }
        return max_area;
    }
};
