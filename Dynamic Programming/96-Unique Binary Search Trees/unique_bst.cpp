class Solution {
public:
    int numTrees(int n) {
        int res[n+1];
        res[0] = 1;//only used when input n = 0!
        for(int i = 1; i <= n ; i ++){
            res[i] = 0;
            for(int first = 1; first <=i; first++){
                int smaller = first - 1;
                int larger = i - first;
                int left = smaller!=0 ? res[smaller] : 1;
                int right = larger!=0 ? res[larger] : 1;
                res[i] += (left*right);
            }
        }
        return res[n];
    }
};
