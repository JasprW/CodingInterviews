#include <vector>;
using namespace std;

class Solution {
   public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if (k > input.size()) return result;
        for (int i = 0; i < k; i++) {
            for (int j = input.size() - 1; j > i; j--) {
                if (input[j] < input[j - 1]) {
                    swap(input[j], input[j - 1]);
                }
            }
        }
        vector<int> result;
        for (int t = 0; t < k; t++) {
            result.push_back(input[t]);
        }
        return result;
    }
};

// TODO: 采用其他排序手段，优化时间复杂度

// 堆排序
class Solution {
   public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        int len = input.size();
        if (input.empty() || k <= 0 || len < k) return result;

        multiset<int, greater<int> > leastNumbers;  // 从大到小排序
        multiset<int, greater<int> >::iterator iterGreater;  // 定义迭代器

        vector<int>::iterator iter = input.begin();
        for (; iter != input.end(); ++iter) {
            // 将前k个数直接插入进multiset中，注意是小于K
            if (leastNumbers.size() < k) {
                leastNumbers.insert(*iter);
            } else {
                // 因为设置的从大到小排序，故multiset中第一个位置的元素即为最大值
                iterGreater = leastNumbers.begin();

                // 如果input中当前元素比multiset中最大元素小，则替换；即保持multiset中这k个元素是最小的。
                if (*iter < *(leastNumbers.begin())) {
                    // 替换掉当前最大值
                    leastNumbers.erase(iterGreater);
                    leastNumbers.insert(*iter);
                }
            }
        }

        for (iterGreater = leastNumbers.begin();
             iterGreater != leastNumbers.end(); ++iterGreater) {
            result.push_back(*iterGreater);  // 将multiset中这k个元素输出
        }

        return result;
    }
};