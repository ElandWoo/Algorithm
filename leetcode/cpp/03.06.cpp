
/*
Solution1： 只利用一个队列
*/
class AnimalShelf {
public:
    queue<vector<int>> shelter;

    AnimalShelf() {}
    
    void enqueue(vector<int> animal) {
        shelter.push(animal);
    }
    
    vector<int> dequeueAny() {
        if (shelter.empty()) return {-1, -1};
        vector<int> front = shelter.front();
        shelter.pop();
        return front;
    }
    
    vector<int> dequeueDog() {
        if (shelter.empty()) return {-1, -1};
        int number = 0;
        if (shelter.front()[1]) {
            vector<int> ans = shelter.front();
            shelter.pop();
            return ans;
        } else {
            vector<int> front = shelter.front();
            number = front[0];
            shelter.pop();
            shelter.push(front);
        }
        
        while (!shelter.front()[1]) {
            if (shelter.front()[0] == number) return {-1, -1};
            vector<int> front = shelter.front();
            shelter.pop();
            shelter.push(front);
        }

        vector<int> ans = shelter.front();
        shelter.pop();
        while (shelter.front()[0] != number) {
            vector<int> front = shelter.front();
            shelter.pop();
            shelter.push(front);
        }
        return ans;
    }
    
    vector<int> dequeueCat() {
        if (shelter.empty()) return {-1, -1};
        int number = 0;
        if (!shelter.front()[1]) {
            vector<int> ans = shelter.front();
            shelter.pop();
            return ans;
        } else {
            vector<int> front = shelter.front();
            number = front[0];
            shelter.pop();
            shelter.push(front);
        }
        

        while (shelter.front()[1]) {
            if (shelter.front()[0] == number) return {-1, -1};
            vector<int> front = shelter.front();
            shelter.pop();
            shelter.push(front);
        }

        vector<int> ans = shelter.front();
        shelter.pop();
        while (shelter.front()[0] != number) {
            vector<int> front = shelter.front();
            shelter.pop();
            shelter.push(front);
        }
        return ans;
    }
};

/*
Solution2: 利用两个队列
*/

class AnimalShelf {
public:
    queue<vector<int>> miao;
    queue<vector<int>> wang;
    AnimalShelf() {}
    
    void enqueue(vector<int> animal) {
        if (animal[1]) wang.push(animal);
        else miao.push(animal);
    }
    
    vector<int> dequeueAny() {
        vector<int> ans;
        if (!miao.empty() && !wang.empty()) {
            if (wang.front()[0] < miao.front()[0]) {
                ans = dequeueDog();
            } else {
                ans = dequeueCat();
            }
        } else if (!miao.empty() && wang.empty()) {
            ans = dequeueCat();
        } else if(miao.empty() && !wang.empty()) {
            ans = dequeueDog();
        } else {
            return {-1, -1}; 
        }
        return ans;
    }
    
    vector<int> dequeueDog() {
        if (wang.empty()) return {-1, -1};
        vector<int> ans = wang.front();
        wang.pop();
        return ans;
    }
    
    vector<int> dequeueCat() {
        if (miao.empty()) return {-1, -1};
        vector<int> ans = miao.front();
        miao.pop();
        return ans;
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */


