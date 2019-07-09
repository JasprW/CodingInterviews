#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string ReverseSentence(string str) {
        if (str.empty()) return str;
        reverse(str.begin(), str.end());
        int low = 0, high = 0;
        while (low < str.size()) {
            while (str[low] == ' ') {
                low++;
            }
            high = low;
            while (high < str.size() && str[high] != ' ') {
                high++;
            }
            reverse(str.begin() + low, str.begin() + high);
            low = high;
        }
        return str;
    }
};