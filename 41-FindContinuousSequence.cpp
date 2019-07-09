#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        int low = 1, high = 2;
        while (high > low) {
            int cur = (high + low) * (high - low + 1) / 2;
            if (cur == sum) {
                vector<int> tmp;
                for (int i = low; i <= high; i++) {
                    tmp.push_back(i);
                }
                result.push_back(tmp);
                low++;
            } else if (cur > sum) {
                low++;
            } else if (cur < sum) {
                high++;
            }
        }
        return result;
    }
};