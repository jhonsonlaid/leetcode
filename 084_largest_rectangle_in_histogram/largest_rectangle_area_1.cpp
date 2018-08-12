public:
    int largestRectangleArea(vector<int>& heights){
        int max_area = 0;
        stack<int> index;
        for(int i = 0; i <= heights.size(); i++){
            while(!index.empty() && (i == heights.size() || heights[i] < heights[index.top()])){
                int h = heights[index.top()];
                index.pop();
                // the top of index is the highest
                // heights[i-1] > h && heights[index.top()] > h
                // so width: (i-1) - (index.top() + 1) + 1
                int w = index.empty() ? i : i - index.top() - 1;
                max_area = max(max_area, w * h);
            }
            index.push(i);
        }
        return max_area;
    }
};
