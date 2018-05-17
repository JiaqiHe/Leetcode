class Solution {
public:
    /* TLE
    * time complexity: O(N)
    */
    // int consecutiveNumbersSum(int N) {
    //     int res = 0;
    //     for(int i = 1; i <= N; i ++) {
    //         if((i%2 == 1 && N%i == 0 && N/i > (i-1)/2) || (i%2 == 0 && (N-i/2)%i == 0 && (N-i/2)/i > i/2 - 1)) {
    //             res++;
    //             // cout<<i<<endl;
    //         }
    //     }
    //     return res;
    // }
    
    int consecutiveNumbersSum(int N) {
        int cur_sum = 0;
        int res = 0;
        int counter = 1;
        while(cur_sum < N) {
            if ( (N - cur_sum)%counter == 0 ) {
                res ++;
            } 
            cur_sum += counter;
            counter ++;
        }
        return res;
    }
};
