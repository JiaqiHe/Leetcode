#include <iostream>
/*
* 浮点数的开方运算
* 输入是一个待开方的数字n，以及要求的精确度prec
* 用binary search
* ⚠️浮点数的陷阱：传统的left <= right不再奏效！因为会有超过精确度要求的小数位的存在，这些小数位会使得在精确度的要求下是相等的，但是数字本身不等。因此将此条件修改为：!(r + prec < l) 
意思就是说，我们本身的期望是，仅考虑精确度范围内的小数位数，如果满足right的那么多小数位和left的那么多小数位是“大于等于”关系就应当继续呆在循环体内。
* 另外一点是设置跳出循环的条件：当mid的平方<=n且（mid+1）的平方>n时，我们就找到了答案：mid，跳出循环体
*/
double sqrt(double n, double prec) {
    if(n <= 0) return 0.0;
    double l = 0, r = max(1.0, n), mid;
    
    while(!(r + prec < l)) {
        mid = l + (r - l)/2;
        // printf("%.6f %.6f %.6f \n", l, mid, r);
        if(mid * mid <= n && (mid + prec)*(mid + prec) > n) return mid;
        if(mid * mid < n) {
            l = mid + prec;
        } else {
            r = mid - prec;
        }
    }
    cout<<"unexpected";
    return r;
}

/* Newton's method
 * 牛顿法求解此问题时，构造函数，找到迭代关系式是第一步。
 * 首先要明确一点，牛顿法给出的答案的平方在时时刻刻都是大于等于n的，我们要根据精确度来调整循环体的条件，如代码中那样。
 * ⚠️跳出循环体时，我们知道，res的平方大于n，res-prec的平方小于n，但这并不意味着我们应该输出res-prec！为什么呢？由于我们只取精确度范围内的长度，有可能res是因为多了后面一串小数位而使得大于n的，如果抹去后面的小数位，是有可能小于n的。举例：n=8，prec=0.000001.在运行末期，我们有res=2.8284217125....它的平方大于8，但是如果仅取小数点后6位：2.828427，它的平方小于n。我们应当输出该数。
*/
double sqrt_newton(double n, double prec) {
    if(n <= 0) return 0.0;
    double res = max(1.0, n);
    while(!(res*res > n && (res-prec)*(res-prec) < n)) {
        res = (res + n/res)/2;
        // printf("%.6f\n", res);
    }
    return pow(((unsigned)(res/prec))*prec,2) > n ? res - prec : res;
}
int main() {
    double n = 8;
    printf("%.6f %.6f\n", sqrt_newton(n, 0.000001), sqrt(n, 0.000001));
    return 0;
}
