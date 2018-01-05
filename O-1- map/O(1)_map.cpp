#include <iostream>
class map_ {
private:
    int a;
    int b;
    int p;
    int N;
    int len;
    vector<int> hashtable;
    vector<pair<int, int>> numbers;
public:
    map_(int N) {
        this->N = N;
        a = 37;
        b = 29;
        p = 10001;
        len = 0;
        hashtable.resize(N, INT_MAX);
    }
    inline int hash(int num) {
        return ((a * num + b) % p) % N;
    }
    void add(int key, int val) {
        len++;
        if(numbers.size() < len) numbers.push_back(make_pair(key, val));
        else numbers[len - 1] = make_pair(key, val);
        //what if there's collision?
        if(hashtable[hash(key)] < len && 
           numbers[hashtable[hash(key)]].first == key) {
            //collision
            N = 2 * N + 1;
            hashtable.resize(N, INT_MAX);
            for(int i = 0; i < len; i ++) {
                hashtable[hash(numbers[i].first)] = i;
            }
        } else {
            hashtable[hash(key)] = len - 1;
        }
    }
    void erase(int key) {
        int position = hashtable[hash(key)];
        //move the last element in numbers
        pair<int, int> last_number = numbers.back();
        numbers[position] = last_number;
        hashtable[hash(last_number.first)] = position;
        len--;
    }
    int find(int key) {
        if(hashtable[hash(key)] < len &&
           numbers[hashtable[hash(key)]].first == key) {
            cout<<"Found! "<<key<<"->"<<numbers[hashtable[hash(key)]].second<<endl;
            return numbers[hashtable[hash(key)]].second;
        }
        else {
            cout<<"Not Found!"<<endl;
            return -1;
        }
    }
    void clear() {
        len = 0;
        cout<<"Cleard!"<<endl;
    }
    void iterate() {
        cout<<"Iteration: ";
        for(int i = 0; i < len; i ++){
            cout<<numbers[i].first<<"->"<<numbers[i].second<<", ";
        }
        cout<<endl;
    }
};
int main() {
    map_ a(100);
    a.add(1,1);
    a.add(2,2);
    a.iterate();
    a.find(3);
    a.find(2);
    a.clear();
    a.find(2);
    a.iterate();
}
