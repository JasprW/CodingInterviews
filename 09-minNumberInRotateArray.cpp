using namespace std;
#include <vector>

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size = rotateArray.size();
        if (size == 0) {
            return 0;
        }
        else {
            for (int i = 0; i < size; i++) {
                if (rotateArray[i] > rotateArray[i + 1]) {
                    return rotateArray[i + 1];
                }
            }
            return rotateArray[0];
        }
    }
};