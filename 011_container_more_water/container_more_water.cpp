/***
 * Time exceed.
 */

class Solution{
public:
    int maxArea(vector<int>& height){
        int n = height.size();
        int max_area = 0, area;
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++){
                area = abs(i - j) * min(height[i], height[j]);  
                max_area = max(area, max_area);
            }
        return max_area;
    }
};
