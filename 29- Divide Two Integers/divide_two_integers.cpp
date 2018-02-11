class Solution {
public:
    int divide(int dividend, int divisor) {
        // corner case: (1) 分子为0 (2) 分母为int_min,分子为-1，此时溢出
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        int res = 0;
        int sign = dividend > 0 ? (divisor > 0 ? 1 : -1) : (divisor > 0 ? -1 : 1);// 另一种机智的写法是用“异或”^
        // 为了解决溢出的问题，全部转化为long long类型来做
        long long denomenator = labs(dividend);
        long long a = labs(divisor);
        while(denomenator >= a) {
            int cur = 1;
            long long numerator = a;// 注意这里也必须是long long类型
            while(denomenator >= (numerator<<1)) {// 把<<1写在判断条件里可以简化代码
                numerator = numerator << 1;
                cur = cur << 1;
            }
            res += cur;
            cout<<res;
            denomenator -= numerator;
        }
        return res*sign;
    }
};

// time complexity: O((logN)^2), N is dividend
// space complexity: O(1)
