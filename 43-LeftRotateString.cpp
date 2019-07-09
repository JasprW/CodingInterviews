#include <string>
using namespace std;

class Solution {
   public:
    string LeftRotateString(string str, int n) {
        int len = str.length();
        if (len == 0) return "";
        n = n % len;
        str += str;
        return str.substr(n, len);
    }
};
