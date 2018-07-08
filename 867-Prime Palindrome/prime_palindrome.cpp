class Solution {
public:
    void nextPalindrome(string &half, bool &even) {
        int num = stoi(half);
        num++;
        string cur_half = to_string(num);
        if(cur_half.length() != half.length()) {
            // carry
            even = !even;
            half = even ? cur_half.substr(0, half.length()) : cur_half;
        }
        else {
            half = cur_half;
        }
    }
    
    bool check(string half, bool even, int N, int &res) {
        string another_half = half;
        reverse(another_half.begin(), another_half.end());
        string num = half + (even ? another_half : another_half.substr(1));
        res = stoi(num);
        return res >= N && isPrime(res);
    }
    
    bool isPrime(int num) {
        if(num == 1) return false;
        for(int i = 2; i <= sqrt(num); i ++) {
            if(num%i == 0) return false;
        }
        return true;
    }
    
    int primePalindrome(int N) {
        int res = 0;
        string s = to_string(N);
        bool even = s.length()%2 == 0;
        string half = s.substr(0, (s.length() + 1)/2);
        while(!check(half, even, N, res)) {
            nextPalindrome(half, even);
        }
        return res;
    }
};
