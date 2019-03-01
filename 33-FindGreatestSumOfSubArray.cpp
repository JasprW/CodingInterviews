#include <vector>;
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())  return 0;
        int sum = array[0], tmp = array[0];
        for(int i = 1; i < array.size(); i++) {
            if(tmp < 0) {
                tmp = array[i];
            } else {
                tmp += array[i];
            }
            sum = sum > tmp ? sum : tmp;
        }
        return sum;
    }
};