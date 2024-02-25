class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 0;
        int prev = 1;

        for (int i = 1; i <= n; i++) {
            int curi = prev + prev2;
            prev2 = prev;
            prev = curi;
        }

        return prev;
    }
};
