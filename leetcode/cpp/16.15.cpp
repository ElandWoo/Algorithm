class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        int n = solution.size();
        // R G B Y
        // G G R R
        // fistly, count hit(guess the correct color for the correct slot) times, 
        // and recorde the position when guess hit; 
        int hit = 0, pseudoHit = 0;
        for (int i = 0; i < n; i++) {
            if (solution[i] == guess[i]) {
                solution[i] = ' ';
                guess[i] = 'N';
                hit++;
            }
        }
        // secondly, count pseudoHit times by searching each un-hitted colors of guess in solution.
        // pseudoHit: guess a color that exists but is in the wrong slot,
        // attentionly, the position doesn't contain the hit site & the correct site.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (solution[j] == ' ' && guess[i] == 'N') continue;
                if (solution[j] == guess[i]) {
                    solution[j] = ' ';
                    guess[i] = 'N';
                    pseudoHit++;
                    break;
                }
            }
        }
        return {hit, pseudoHit};
    }
};
