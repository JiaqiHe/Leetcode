class ZigzagIterator {
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty()) q.push(make_pair(v1.begin(), v1.end()));
        if(!v2.empty()) q.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        pair<vector<int>::iterator, vector<int>::iterator> cur = q.front();
        q.pop();
        int toReturn = *cur.first;
        if(cur.first + 1 != cur.second) q.push(make_pair(cur.first + 1, cur.second));
        return toReturn;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
