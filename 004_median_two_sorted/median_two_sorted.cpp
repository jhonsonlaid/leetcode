/*** Not Work ***/ 

class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        // i: nums1 index, j: nums2 index
        // m1 is  nums1 mid
        int l1 = nums1.length(), l2 = nums2.length();
        int i = l1/2, j = l2/2;
        int is_even = (l1+l2)%2;
        int small = 0, big = 0;
        int m1 = nums1[i/2], m2 = nums2[j/2];
        int k = 2;
        while(true){
            if(m1 > m2){
                small += l2/k;
                big += l1/k;
            }
            else{
                small += l1/k;
                big += l2/k;
            }

            if(is_even){
                int mid = (l1+l2)/2 - 1;
                
            }
            else{
                int mid = (l1+l2)/2;
                if(small >= mid){
                    return nums1[i];
                }
                else if(big <= mid){
                    return nums2[j];
                }
            }

            k *= 2;
            if(m1 > m2){
                i = (l1-i)/2;
                j = j/2;
                m1 = nums1[j];
                m2 = nums2[i];
            }
            else{
                i = i/2;
                j = (l2-i)/2;
                m1 = nums1[i];
                m2 = nums2[j];
            }
        }
};
