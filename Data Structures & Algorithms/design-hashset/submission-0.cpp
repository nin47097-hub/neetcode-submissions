class MyHashSet {
private:  

    vector<int> data;

public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(find(data.begin(), data.end(), key )==data.end()){
            data.push_back((key));

        }
        

        
    }
    
    void remove(int key) {
        auto k = find(data.begin(), data.end(), key) ;
        if(find(data.begin(), data.end(), key )!=data.end()){
            data.erase(k);

        }
        
    }
    
    bool contains(int key) {
        if(find(data.begin(), data.end(), key )!=data.end()){
            return true;

        }else{
            return false;
        }
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */