class ZigzagIterator {
private:
    pair<int, int> next_;
    vector<int> v1;
    vector<int> v2;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        this->v1 = v1.empty() ? v2 : v1;
        this->v2 = v1.empty() ? v1 : v2;
        next_ = make_pair(1, 0);
    }

    int next() {
        int toReturn = next_.first == 1 ? v1[next_.second] : v2[next_.second];
        if(next_.first == 1) {
            if(next_.second < v2.size()) next_ = make_pair(2, next_.second);
            else next_ = make_pair(1, next_.second + 1);
        } else {
            if(next_.second + 1 < v1.size()) next_ = make_pair(1, next_.second + 1);
            else next_ = make_pair(2, next_.second + 1);
        }
        return toReturn;
    }

    bool hasNext() {
        if((next_.first == 1 && next_.second < v1.size()) || (next_.first == 2 && next_.second < v2.size())) return true;
        else return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
