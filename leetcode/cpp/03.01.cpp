class TripleInOne {
public:
    TripleInOne(int stackSize) {
        size = stackSize * 3;
        array.assign(size, 0);
        top.assign({-3, -2, -1});
    }
    
    void push(int stackNum, int value) {
        if (top[stackNum] + 3 >= size) return;
        top[stackNum] += 3;
        array[top[stackNum]] = value;
    }
    
    int pop(int stackNum) {
        if (top[stackNum] < 0) return -1;
        int res = array[top[stackNum]];
        top[stackNum] -= 3;
        return res;
    }
    
    int peek(int stackNum) {
        if (top[stackNum] < 0) return -1;
        return array[top[stackNum]];
    }
    
    bool isEmpty(int stackNum) {
        return top[stackNum] < 0;
    }

private:
    vector<int> array;
    // def: a array to recorde the top index of each stack
    vector<int> top;
    // def: the size of the array
    int size;
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */