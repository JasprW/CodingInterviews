#include <map>;
#include <vector>;
using namespace std;

class Solution {
   public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if (!len) return 0;
        map<int, int> num;
        for (int i = 0; i < len; i++) {
            map<int, int>::iterator itr = num.find(numbers[i]);
            if (itr != num.end()) {
                itr->second++;
            } else {
                num.insert(std::pair<int, int>(numbers[i], 1));
            }
        }
        map<int, int>::iterator itr = num.begin();
        while (itr != num.end()) {
            if (itr->second > (len / 2)) {
                return itr->first;
            }
            itr++;
        }
        return 0;
    }
};

class Solution {
   public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) return 0;

        // 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
        int result = numbers[0];
        int times = 1;  // 次数

        for (int i = 1; i < numbers.size(); ++i) {
            if (times == 0) {
                // 更新result的值为当前元素，并置次数为1
                result = numbers[i];
                times = 1;
            } else if (numbers[i] == result) {
                ++times;  // 相同则加1
            } else {
                --times;  // 不同则减1
            }
        }

        // 判断result是否符合条件，即出现次数大于数组长度的一半
        times = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            if (numbers[i] == result) ++times;
        }

        return (times > numbers.size() / 2) ? result : 0;
    }
};
