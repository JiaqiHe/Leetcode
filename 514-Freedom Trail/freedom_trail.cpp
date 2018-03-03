class Solution {
public:
    /*
    思路：每次都顺时针和逆时针扭动，找到两种情况下需要的步数和结束的位置。这样，我们就算做完了当前字母的匹配。
    接下来，对于剩下的字符串我们做同样的事情，注意这里就表明是⚠️递归了。
    假设我们的程序可以给我们答案，接下来需要组合答案，分别加到之前对应的步数上去，取小的那个，就是答案
    但是！！！！TLE！！！这是为什么呢？因为这里面有很多重复计算：你想，先逆时针转的时候，函数不停加入call stack，直到走到最底层；
    好，当我们再顺时针转的时候，难免会遇到需要求解刚才已经遇到过的问题。
    所以呢，我们可以加入memorization的环节，算出一步答案我们就存一下，不管要不要用，之后再去查我们有没有解过这个问题，如果有记录，那就直接把结果拿过来
    
    另一个注意点是：
    此题不能依靠局部最优，也就是说，就算当前的字母顺时针转比逆时针转要少步数，也不能说最后的结果一定是顺时针转的！！“笑到最后的才是赢家”的感觉
    */
    int computeSteps(string ring, int ptr, int dir, char target) {
        int res = 0;
        while(ring[ptr] != target) {
            res++;
            ptr = (ptr + dir + ring.length())%(ring.length());
        }
        return res;
    }
    int findRotateSteps(string ring, string key, int ptr, unordered_map<string, int> &dict) {
        if(key.empty()) return 0;
        char target = key[0];
        string hashkey = to_string(ptr) + key;
        if(dict.find(hashkey) != dict.end()) return dict[hashkey];
        int left_steps = computeSteps(ring, ptr, -1, target);
        int right_steps = computeSteps(ring, ptr, 1, target);
        int ptr_goleft = (ptr - left_steps + ring.length())%ring.length();
        int ptr_goright = (ptr + right_steps + ring.length())%ring.length();
        int go_left = findRotateSteps(ring, key.substr(1), ptr_goleft, dict);
        int go_right = findRotateSteps(ring, key.substr(1), ptr_goright, dict);
        int cur_res = min(left_steps + 1 + go_left, right_steps + 1 + go_right);
        dict[hashkey] = cur_res;
        return cur_res;
    }
    

    int findRotateSteps(string ring, string key) {
        unordered_map<string, int> dict;
        return findRotateSteps(ring, key, 0, dict);
    }
};
