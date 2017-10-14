class RandomizedSet {
private:
    unordered_set<int> database;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(database.find(val) == database.end()){
            database.insert(val);
            return true;
        }
        else return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(database.find(val) != database.end()){
            database.erase(val);
            return true;
        }
        else return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        unordered_set<int>::iterator it = database.begin();
        int t = rand()%database.size();
        while(t!=0){
            t--;
            it++;
        } 
        return *it;
    }
};
