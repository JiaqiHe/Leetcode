// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    queue<char> q;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    
    //这道题的意思是：调用多次read，存到相应的buf中去。但是呢，问题是，有可能之前多读了一些没用上，下次读的时候要求把没用上的先给用了再读后面的
    int read(char *buf, int n) {
        int res = 0;
        while(res < n && !q.empty()) {
            *(buf + res) = q.front();
            res++;
            q.pop();
        }
        int step = 0;
        for(int i = res; i < n; i += step) {
            step = read4(buf + res);
            if(!step) break;
            res += step;
        }
        // if res > n, it means that we have read more than we wanted
        for(int i = n; i < res; i ++) {
            q.push(*(buf + i));
        }
        return min(res, n);
    }
    
    
    
};
