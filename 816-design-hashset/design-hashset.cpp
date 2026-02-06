class MyHashSet {
private: 
    static const int size = 1000;
    vector<list<int>> buckets;
public:
    MyHashSet() {
        buckets.resize(size);
    }

    int hash(int key){
        return key % size;
    }
    
    void add(int key) {
        int index = hash(key);

        for (int num : buckets[index]){
            if (num == key) return ;
        }
        buckets[index].push_back(key);
    }
    
    void remove(int key) {
        int index = hash(key);
        buckets[index].remove(key);
    }
    
    bool contains(int key) {
        int index = hash(key);

        for (int num : buckets[index]){
            if(num == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */