class Solution{
public:
    int trap(vector<int>& height){
        if(height.size() < 3) return 0;
        int cap = 0;
        for(int i= 1; i < height.size()-1;){
            cap += forward(height, i);
        }
        return cap;
    }

    int forward(vector<int>& height, int& start){
        int pos = start + 1;

        for(int i = start + 1; i < height.size(); i++){
            if(height[i] >= height[start]){
                int cap = height[start] * (i - start - 1);
                int bh = 0;
                for(int j = start + 1; j < i; j++){
                    bh += height[j];
                }
                cap -= bh;
                start = i;
                return max(cap, 0);
            }
            if(height[i] > height[pos]){
                pos = i;
            }
        }
		cout << pos << endl;
        int cap = height[pos] * (pos - start - 1);
        int bh = 0;
        for(int j = start + 1; j < pos; j++){
            bh += height[j];
        }
        cap -= bh;
        start = pos;
        return cap;
    }
};
