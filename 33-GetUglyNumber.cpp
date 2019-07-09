#include <queue>;
using namespace std;

class Solution {
   public:
    int GetUglyNumber_Solution(int index) {
        if (index < 7) return index;
        int p2 = 0, p3 = 0, p5 = 0, newNum = 1;
        vector<int> arr;
        arr.push_back(newNum);
        while (arr.size() < index) {
            newNum = min(arr[p2] * 2, min(arr[p3] * 3, arr[p5] * 5));
            if (newNum == arr[p2] * 2) p2++;
            if (newNum == arr[p3] * 3) p3++;
            if (newNum == arr[p5] * 5) p5++;
            arr.push_back(newNum);
        }
        return newNum;
    }
};