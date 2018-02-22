class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while(n) {
            digits.push_back(n%10);
            n /= 10;
        }
        //digits stores the digits of n, 0->ones digit, 1->tens digit, ...
        int ptr = 1;
        while(ptr < digits.size() && digits[ptr] >= digits[ptr-1] ) {
            ptr++;
        }
        if(ptr == digits.size()) return -1;
        //find appropriate digit to swap
        //now ptr is pointing to the place that waits to be swapped
        int target = digits[ptr];
        int toSwap = 0;
        while(digits[toSwap] <= target) toSwap++;
        swap(digits[ptr], digits[toSwap]);
        sort(digits.begin(), digits.begin() + ptr - 1);
        reverse(digits.begin(), digits.begin() + ptr);
        long res = 0;
        for(int i = digits.size() - 1; i >= 0; i --) {
            res = res * 10 + digits[i];
        }
        if(res > INT_MAX) return -1;
        else return (int)res;
    }
};
