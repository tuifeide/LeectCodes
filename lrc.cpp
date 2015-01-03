class LRUCache{
public:
    int cap;
    int **Cache;
    LRUCache(int capacity) {
        this->cap = capacity;
        Cache = new int *[capacity];
        for (int i = 0; i < capacity; i++) {
            Cache[i] = new int[3];
            for(int j = 0; j < 3; j++) {
                Cache[i][j] = -1;
            }
        }
    }
    
    int get(int key) {
        int val = -1;
        for(int i = 0; i < this->cap; i++) {
            if(Cache[i][0] != key) {
                Cache[i][2] --;
            }
            else {
                Cache[i][2] = this->cap - 1;
                val = Cache[i][1];
            }
        }
        return val;
    }
    
    void set(int key, int value) {
        int idx = 0, min = this->cap;
        bool flag_et = false;
        for(int i = 0; i < this->cap; i++) {
            if(Cache[i][0] != key) {
                if(Cache[i][2] < min) {
                    min = Cache[i][2];
                    idx = i;
                }
                Cache[i][2] --;
            }
            else {
                Cache[i][1] = value;
                Cache[i][2] = this->cap - 1;
                flag_et = true;
            }
        }
        if(!flag_et) {
            Cache[idx][0] = key;
            Cache[idx][1] = value;
            Cache[idx][2] = this->cap - 1;
        }
    }
};
