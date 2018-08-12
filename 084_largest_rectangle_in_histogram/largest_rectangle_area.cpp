class Solution{
public:
    int largestRectangleArea(vector<int>& heights){
        int max_area = 0;
        for(int i = 0; i < heights.size(); i++){
            int left = i, right = i, h = heights[i];
            while(left-1 >= 0 && heights[left-1] >= h) left--;
            while(right+1 < heights.size() && heights[right+1] >= h) right++;
            int area = (right - left + 1) * h;
            max_area = max(max_area, area);
        }
        return max_area;
    }
};
