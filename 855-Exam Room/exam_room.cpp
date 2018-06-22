class ExamRoom {
private:
    struct compare {
        int operator()(int a, int b) {
            return a > b;
        }
    };
    
    int N;
    priority_queue<int, vector<int>, compare> pq;
    unordered_set<int> left;
    int counter;
    
public:
    ExamRoom(int N) {
        this->N = N;
        this->counter = 0;
    }
    
    int seat() {
        if(counter == 0) {
            priority_queue<int, vector<int>, compare> new_pq;
            new_pq.push(0);
            left.clear();
            pq = new_pq;
            counter = 1;
            return 0;
        }
        else {
            int last = 0, cur, distance = INT_MIN, cur_distance, place = -1;
            priority_queue<int, vector<int>, compare> new_pq;
            while(!pq.empty()) {
                cur = pq.top();
                pq.pop();
                if(left.find(cur) == left.end()) {
                    new_pq.push(cur);
                    cur_distance = last + (cur - last)/2 - last - 1;
                    if(cur_distance > distance) {
                        distance = place == -1 ? cur - 1 : cur_distance;
                        place = place == -1 ? 0 : last + (cur - last)/2;
                    }
                    last = cur;
                }
                else {
                    left.erase(cur);
                }
            }
            cur_distance = N - 1 - last - 1;
            if(cur_distance > distance) {
                place = N - 1;
            }
            if(place >= 0) new_pq.push(place);
            pq = new_pq;
            counter = new_pq.size();
            return place;
        }
    }
    
    void leave(int p) {
        left.insert(p);
        counter--;
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
