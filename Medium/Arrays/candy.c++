class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        int total = 1;
        int up = 0, down = 0, peak = 0;

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) {        // going up
                up++;
                peak = up;
                down = 0;
                total += 1 + up;        // current gets (up+1)
            } else if (ratings[i] == ratings[i-1]) { // flat
                up = down = peak = 0;
                total += 1;             // reset valley
            } else {                    // going down
                up = 0;
                down++;
                total += down;          // add 1,2,3,... along the down-slope 
                                        // already added the down slope, so now only need to bump the peak
                if (down > peak) total += 1; // bump the peak when needed
            }
        }
        return total;
    }
};