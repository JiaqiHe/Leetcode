class Solution {
public:
    // binary search
    // 不用考虑edge case（i=0 或者 i=m 或者 j=0 或者 j=n）。一旦有这种情况出现，那么此时的i和j一定是答案了。为什么呢？因为i和j都是从最中间开始的
    // 如果有一个变成了其中一种edge case，那么一定是“历史的选择”，也就是说，之前的所有判断都迫使其走向这个edge case，然而一旦走到这个edge case，就到头了
    // 所以这些edge case都是答案，都在最后的else break处理
    // 这也使得binary search的条件可以写的如此简洁，只要保证不等式的前提成立，以及不等式本身成立即可
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);//⚠️机智的换参方法
        int left = 0, right = m;
        int i, j;
        while(left <= right) {
            i = left + (right - left)/2;
            j = (m + n + 1)/2 - i;
            if(j < n && i > 0 && nums1[i-1] > nums2[j]) right = i;
            else if(i < m && j > 0 && nums1[i] < nums2[j-1]) left = i + 1;
            else break;
        }
        double first_half_max = max(i == 0 ? INT_MIN : nums1[i-1], j == 0 ? INT_MIN : nums2[j-1]);
        double second_half_min = min(i == m ? INT_MAX : nums1[i], j == n ? INT_MAX : nums2[j]);
        return (m+n)%2 == 0 ? (first_half_max + second_half_min)/2.0 : first_half_max;
    }
};
