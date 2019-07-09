class Solution {
   public:
    bool Find(vector<vector<int>> array, int target) {
        int rowCount = array.size();
        int colCount = array[0].size();
        int i, j;
        for (i = rowCount - 1, j = 0; i >= 0 && j < colCount;) {
            if (target == array[i][j]) return true;
            if (target < array[i][j]) {
                i--;
                continue;
            }
            if (target > array[i][j]) {
                j++;
                continue;
            }
        }
        return false;
    }
};