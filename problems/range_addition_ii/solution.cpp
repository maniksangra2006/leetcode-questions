 class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_Row = m;
        int min_Col = n;

        for (auto& op : ops) {
            min_Row = min(min_Row, op[0]);  // smallest ai
            min_Col = min(min_Col, op[1]);  // smallest bi
        }

        return min_Row * min_Col;
    }
};