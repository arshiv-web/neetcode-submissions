class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int n = nums1.size() + nums2.size();
        int half = (n+1)/2;

        int l = 0;
        int r = nums1.size();

        while(l<=r) {
            int m1 = l + (r-l)/2;
            int m2 = half - m1;

            int l1 = m1-1 >= 0 ? nums1[m1-1] : INT_MIN;
            int l2 = m2-1 >= 0 ? nums2[m2-1] : INT_MIN;
            int r1 = m1 < nums1.size() ? nums1[m1] : INT_MAX;
            int r2 = m2 < nums2.size() ? nums2[m2] : INT_MAX;


            if(l1 <= r2 && l2 <= r1) {
                if(n%2 == 0) return (max(l1, l2) + min(r1, r2))/2.0;
                else return max(l1, l2)/1.0;
            } else if(l1 > r2) {
                r = m1 - 1;
            } else if(l2 > r1) {
                l = m1 + 1;
            }
        } 
        return 0.0;

    }
};
