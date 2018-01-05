#include <iostream>
class set_ {
private:
    const int a = 29;
    const int b = 37;
    int p = 101;
    vector<int> hashtable;
    vector<int> numbers;
    int len = 0;
public:
    set_() {
        hashtable.resize(p, -1);
    }//constructor
    int hash(int x) {
        return (a * x + b) % p;
    }
    
    void insert(int num) {
        numbers.push_back(num);
        int hashed = hash(num);
        len++;
        if(hashtable[hashed] != -1 && 
           hashtable[hashed] < len && 
           find(numbers[hashtable[hashed]])) {
            //collision
            p = (p - 1) * 10 + 1;
            hashtable.resize(p, -1);
            for(int i = 0; i < len; i ++){
                int hashed = hash(numbers[i]);
                hashtable[hashed] = i;
            }
        } else hashtable[hashed] = numbers.size() - 1;
    }
    
    bool find(int num) {
        int hashed = hash(num);
        if(hashtable[hashed] != -1 && 
           hashtable[hashed] < len && 
           numbers[hashtable[hashed]] == num) return true;
        else return false;
    }
    
    void erase(int num) {
        int hashed = hash(num);
        int index = hashtable[hashed];
        int last = numbers.back();
        numbers[index] = last;
        numbers.erase(numbers.begin() + numbers.size() - 1);
        int hashed_last = hash(last);
        hashtable[hashed_last] = index;
        len--;
    }
    
    void clear() {
        len = 0;
    }
    
    vector<int> traverse() {
        vector<int> res;
        for(int i = 0; i < len; i ++){
            cout<<numbers[i]<<" ";
            res.push_back(numbers[i]);
        }
        cout<<endl;
        return res;
    }
    
};

int main() {
    set_ a;
    a.insert(1);
    a.traverse();
    a.insert(2);
    a.traverse();
    cout<<a.find(2)<<endl;
    cout<<a.find(3)<<endl;
    a.clear();
    cout<<a.find(2)<<endl;
    
}
