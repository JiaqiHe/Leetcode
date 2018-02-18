class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int cur = 1;
        for(int i = 0; i < n; i ++) {
            res.push_back(cur);
            //start to update cur to the next value to push into vector
            // first consider adding 0 at the end
            if(cur * 10 <= n) {
                cur *= 10;
            } else {
                //second, consider adding 1,2,3,...
                if(cur >= n) cur /= 10;
                cur++;
                // everytime we find cur has zero at the end, we have to delete them first to maintain lexicographical order
                // no need to worry because we would add them back
                while(cur%10 == 0) {
                    cur /= 10;
                }
            }
        }
        return res;
    }
};
