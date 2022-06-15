class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        Hanoi(n, A, B, C);
    }

private:
    void Hanoi(int n, vector<int>& A, vector<int>& B, vector<int>& C) {
        if (n > 0) {
            // 1. mov the top n - 1 disks of tower A to B by C;
            Hanoi(n - 1, A, C, B);
            // 2. mov the top disk of A to C;
            C.push_back(A.back());
            A.pop_back();
            // 3. mov the n - 1 disks of B to C by A;
            Hanoi(n - 1, B, A, C);
        }
    }
};