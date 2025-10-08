class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        int numberOfArrows = 1;
        // Sort by end coordinate
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int arrowPosition = points[0][1];

        for (int i = 1; i < points.size(); ++i) {
            if (arrowPosition < points[i][0]) {
                ++numberOfArrows;
                arrowPosition = points[i][1];
            }
        }

        return numberOfArrows;
    }
};