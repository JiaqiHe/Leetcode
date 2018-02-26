class Solution {
public:
    /*
    * 本题属于binary search
    * 我们想要找一个数，如果没找到，我们只能接受比它小的
    * 属于“如果没search到，则输出比目标值小的最大元素的index”类型
    * 
    * 思路：
    * 首先对citations进行降序排序，然后我们要找的是满足 citations[i] > i+1 的最大的i
    */
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());
        int left = 0, right = citations.size() - 1, mid;
        while(left <= right) {
            mid = left + (right - left)/2;
            if(citations[mid] == mid + 1) return mid + 1;
            else if(citations[mid] > mid + 1) left = mid + 1;
            else right = mid - 1;
        }
        return min(mid, right) + 1;
    }
};
