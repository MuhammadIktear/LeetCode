class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
        sort(v.begin(), v.end());
        int closestSum = INT_MAX;
        int minDiff = INT_MAX;

        for (int i = 0; i < v.size() - 2; i++) {
            int l = i + 1;
            int r = v.size() - 1;
            int currentNum = v[i];

            while (l < r) {
                int currentSum = currentNum + v[l] + v[r];
                int currentDiff = abs(currentSum - target);

                if (currentDiff < minDiff) {
                    minDiff = currentDiff;
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return closestSum;
    }
};
