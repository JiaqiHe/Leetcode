class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //count bits at every position
        int bits[32];
        vector<int> res;
        for(int i = 0; i < 32; i ++){
            bits[i] = 0;
            int a = 0;
            int aXORb = 0;
            for(int j = 0; j < nums.size(); j ++){
                aXORb = aXORb ^ nums[j];
                if(nums[j] & (1 << i)){
                    a = a ^ nums[j];
                    bits[i]++;
                } 
            }
            if(bits[i]%2){
                res.push_back(a);
                res.push_back(aXORb ^ a);
                return res;
            } 
        }
    }
};
