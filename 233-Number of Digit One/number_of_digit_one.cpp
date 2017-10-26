class Solution {
public:
    
    int n_digit_max[11];
    void precompute(){
        for(int i = 1; i <= 10; i ++){
            n_digit_max[i] = i*(pow(10, i-1));
        }
    }
    
    vector<int> determine_digits(int n){
        int n_copy = n;
        vector<int> result;
        int res = 0;
        int first_digit = 0;
        int remain = 0;
        while(n != 0){
            first_digit = n%10;
            n /= 10;
            res++;
        } 
        remain = n_copy - first_digit*pow(10, res-1);
        result.push_back(res);
        result.push_back(first_digit);
        result.push_back(remain);
        return result;
    }
    
    int count1s(int n){
        int res = 0;
        while(n!=0){
            if(n%10 == 1) res++;
            n/=10;
        }
        return res;
    }
    
    int countDigitOne(int n) {
        int res = 0;
        if(n<=0) return 0;
        if(n<10) return 1;
        precompute();
        vector<int> cur = determine_digits(n);
        res += cur[1]==1? cur[2]+1 : pow(10, cur[0]-1);
        res += cur[1]*n_digit_max[cur[0]-1] + countDigitOne(cur[2]);
        cout<<res<<endl;
        return res;
    }
};
