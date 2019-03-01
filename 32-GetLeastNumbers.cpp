#include <vector>;
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if(k > input.size()) return result;
        for(int i=0; i<k; i++) {
            for(int j=input.size()-1; j>i; j--) {
                if(input[j] < input[j-1]) {
                    swap(input[j], input[j-1]);
                }
            }
        }
        vector<int> result;
        for(int t=0; t<k; t++) {
            result.push_back(input[t]);
        }
        return result;
    }
};

//TODO: 采用其他排序手段，优化时间复杂度