#include <math.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    int StrToInt(string str) {
        int len = str.size();
        for (int i = 1; i < len; i++) {
            if (str[i] < '0' || str[i] > '9') {
                return 0;
            }
        }
        int result = 0, sign = 0;
        if ((str[0] > '0' && str[0] < '9') || str[0] == '+' || str[0] == '-') {
            if (str[0] == '-') {
                sign = -1;
            } else if (str[0] == '+') {
                sign = 1;
            }
            int t = sign == 0 ? 0 : 1;
            for (int i = t; i < len; i++) {
                result += (str[i] - '0') * pow(10, (len - 1 - i));
            }
            return sign == 0 ? result : sign * result;
        } else {
            return 0;
        }
    }
};

int main() {
    cout << StrToInt("-44123");
    return 1;
}