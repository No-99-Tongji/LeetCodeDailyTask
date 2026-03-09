class Solution {
public:
    int getKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        int it1 = 0, it2 = 0;

        while (true) {
            if (it1 == m) return nums2[it2 + k - 1];
            if (it2 == n) return nums1[it1 + k - 1];
            if (k == 1) return min(nums1[it1], nums2[it2]);

            int newIt1 = min(m-1, it1 + k / 2 - 1);
            int newIt2 = min(n-1, it2 + k / 2 - 1);
            int num1 = nums1[newIt1];
            int num2 = nums2[newIt2];

            if (num1 < num2) {
                k -= newIt1 - it1 + 1;
                it1 = newIt1 + 1;
            } else {
                k -= newIt2 - it2 + 1;
                it2 = newIt2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};